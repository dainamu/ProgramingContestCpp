#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;

void isIsland(vector<string> a, vector<vector<bool>> &isChecked, int x, int y) {

	
	// チェック済みの場合、リターン
	if (isChecked.at(x).at(y)) {
		return;
	}
	
	// 現在のマスをチェック済みにする
	isChecked.at(x).at(y) = true;

	// 現在のマスの状態
	char c =  a.at(x).at(y);

	if (c == '-' || c == 'x') {
		// 陸地以外の場合
		return;
	}



	// 上下左右に対して呼び出す
	isIsland(a, isChecked, x + 1, y);
	isIsland(a, isChecked, x - 1, y);
	isIsland(a, isChecked, x, y+1);
	isIsland(a, isChecked, x, y-1);

	


}

int main() {

	vector<string> a(12);

	a.at(0) = "------------";
	a.at(11) = "------------";
	for(int i = 1; i<11; i++){

		string tmp;
		cin >> tmp;
		tmp = '-' + tmp + '-';

		a.at(i) = tmp;
	}

	// まずすべての陸地ますがつながっているかを調べる関数
	// すべての陸地がつながっている→あるひとつの陸地ますから上下左右の移動を繰り返して、全ての陸地にたどりつける。


	// 陸地マスを一つ探す
	int x, y;
	bool ans = true;
	// 全てのマスを埋め立てる対象として1つの島になるか
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			char tmp = a.at(i).at(j);
			a.at(i).at(j) = 'o';// 陸地にする

			// 再帰関数を呼び出してisCheckedを埋める
			// チェック用配列
			vector<vector<bool>> isChecked(12, vector<bool>(12, false));
			isIsland(a, isChecked, i, j);

			// 陸地すべてをチェックずみであれば一つのしま

			for (int i = 1; i < 11; i++) {
				for (int j = 1; j < 11; j++) {
					if (a.at(i).at(j) == 'o') {
						if (isChecked.at(i).at(j) == false) {
							// 陸地をチェックできていない。
							ans = false;
						}
					}
				}
			}

			if (ans) {
				goto exit;
			}
			a.at(i).at(j) = tmp;// マスを元にもどす


		}

	}


exit:
	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}