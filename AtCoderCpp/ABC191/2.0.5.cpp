#include <iostream>
#include <vector>

using namespace std;


// 再帰関数
int r(vector<vector<int>> &parent, int x) {

	// ベースケース
	if (parent.at(x).size() == 0) {
		return 0;
	}

	int max_time = 0;

	for (int c : parent.at(x)) {
		// 子要素全てに調査

		int r_time = r(parent, c) + 1; // 報告書が揃ってかえって来る時刻は子要素で報告書が揃った時刻＋１

		// どっちが大きいか、大きいほうが答えの時刻
		max_time = max(max_time, r_time);

	}
	
	return max_time;
}

int main_() {

	int N;

	cin >> N;

	vector<int>  P(N);
	P.at(0) == 0;
	for (int i = 1; i < N; i++) {

		cin >> P.at(i); // i番目の親の番号
	}

	vector<vector<int>> parent(N);

	for (int i = 1; i < N; i++) {
		// 各要素ごとの子要素の配列
		parent.at(P.at(i)).push_back(i);
	}

	// 0番目の組織の元に報告書が揃う時刻を求める。
	cout << r(parent, 0) << endl;

	return 0;
}
