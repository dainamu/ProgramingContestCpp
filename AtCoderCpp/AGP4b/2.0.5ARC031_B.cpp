#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;

void fill_island(vector<string> borad, vector<vector<bool>> &isChecked, int x, int y) {

	// 場外の場合はリターン
	if (x < 0 || x > 9 || y < 0 || y>9) return;
	// チェック済みの場合、リターン
	if (isChecked.at(x).at(y)) {
		return;
	}
	
	// 現在のマスをチェック済みにする
	isChecked.at(x).at(y) = true;

	if (borad[x][y] == 'x') {
		// 海の場合
		return;
	}



	// 上下左右に対して呼び出す
	fill_island(borad, isChecked, x + 1, y);
	fill_island(borad, isChecked, x - 1, y);
	fill_island(borad, isChecked, x, y+1);
	fill_island(borad, isChecked, x, y-1);

}

bool check_connected(vector<string> board, int x, int y) {

	// チェック用配列
	vector<vector<bool>> isChecked(10, vector<bool>(10, false));

	// 再帰関数でisCheckedを完成させる
	fill_island(board, isChecked, x, y);

	bool ans = true;
	req(i, 10) {
		req(j, 10) {
			if (board[i][j] == 'o') {
				// 陸地でチェックされていなければNG
				if (isChecked[i][j] == false) {
					ans = false;
				}
			}
		}
	}

	return ans;

}

int main_ARC031_B() {

	vector<string> board(10);

	req(i, 10) cin >> board[i];

	bool ans = true;

	// 全てのマスを埋め立てる対象として1つの島になるか
	req(i, 10){
		req(j, 10){

			if (board.at(i).at(j) == 'o') continue;

			char tmp = board.at(i).at(j); // 処理中のマスを退避
			board.at(i).at(j) = 'o';// 陸地にする

			if (check_connected(board, i, j)) {
				cout << "YES" << endl;
				return 0;
			}

			board.at(i).at(j) = tmp;// マスを元にもどす


		}

	}

	cout << "NO" << endl;
	return 0;
}