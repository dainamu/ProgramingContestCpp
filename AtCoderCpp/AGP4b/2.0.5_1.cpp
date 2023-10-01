#include <iostream>
#include <vector>
using namespace std;


// 正しい移動かを調べる（y、x）が移動先
bool is_valid_move(vector<string>& board, vector<vector<bool>>& checked, int x, int y) {
	
	int N = board.size();

	// 移動先がマス目の外である場合
	if (x <= -1 || x >= N || y <= -1 || y >= N) {
		return false;
	}

	// 移動先が壁
	if (board.at(y).at(x) == '#') {

		return false;
	}

	// すでに調べているマスへの移動は調べないのでfalse
	if (checked.at(y).at(x)) {
		return false;

	}

	// それ以外は正しい移動
	return true;

}

// (y, x) にいる状態からゴールに到達できるか
// board: マス目の種類
// checked: そのマスをすでに調べたかを持つ二次元配列
bool reachable(vector<string>& board, vector<vector<bool>>& checked, int x, int y) {

	int N = board.size();

	// ベースケース
	if (x == N - 1 && y == N - 1) {
		return true;
	}

	// 再帰ステップ
	checked.at(y).at(x) = true; // すでに調べている状態しておく

	// 「上」「右」「下」「左」のいずれかの移動でゴールに到達できるか？
	bool result = false;

	// 上へ移動したマスからゴールに到達できるか？
	if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) {
		result = true;
	}

	//  左へ移動したマスからゴールに到達できるか？
	if (is_valid_move(board, checked, x-1, y) && reachable(board, checked, x - 1, y)) {
		result = true;
	}

	// 下へ移動したマスからゴールに到達できるか？
	if (is_valid_move(board, checked, x, y+1) && reachable(board, checked, x, y+1)) {
		result = true;
	}
	// 右へ移動したマスからゴールに到達できるか？
	if (is_valid_move(board, checked, x+1, y) && reachable(board, checked, x+1, y)) {
		result = true;
	}

	return result;

}


int main_2051() {
	// 引数の配列を変化させる例
	
	int N;

	cin >> N;

	vector<string> board(N);

	for (int i = 0; i < N; i++) {
		cin >> board.at(i);
	}

	// すでにそのマスを調べたかを保持する二次元配列
	vector<vector<bool>> checked(N, vector<bool>(N, false)); // 初期値false

	// (0, 0) からゴールへ到達できるか
	if (reachable(board, checked, 0, 0)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}