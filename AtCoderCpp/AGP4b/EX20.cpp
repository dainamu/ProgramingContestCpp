#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;

int count_report_num(vector<vector<int>> &children, int x) {

	if (children.at(x).size == 0) {
		return 1;
	}

	int sum = 0;
	for (int i = 0; i < children.at(x).size(); i++) {
		sum += count_report_num(children, children.at(x).at(i));
	}
	sum += 1;
	return sum;

}

int main_EX20() {

	int N;
	cin >> N;

	vector<int> p(N); // 各組織kの親組織を示す配列
	p.at(0) = -1; // 0番組織の親組織は存在しないので-1をいれておく。

	for (int i = 1; i < N; i++) {
		cin >> p.at(i);
	}

	// 組織の菅家英から2次元配列を作る
	vector<vector<int>> children(N); // ある組織の子組織の番号一覧
	
	for (int i = 1; i < N; i++) {
		int parent = p.at(i); // i番の親曽木の番号
		children.at(parent).push_back(i); // parentの子組織一覧にi番を追加

	}

	for (int i = 0; i < N; i++) {
		cout << count_report_num(children, i) << "\n";
	}

	return 0;
}