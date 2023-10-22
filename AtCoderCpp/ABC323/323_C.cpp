#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#include <compare>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

bool desc_asc(pair<int, char>& left, pair<int, char>& right) {
	if (left.first == right.first) {
		return left.second < right.second;
	}
	else {
		return right.first < left.first;
	}
}

signed main() {


	int n, m; // n プレイヤー数 m 問題数
	cin >> n >> m;

	vector<int> a(m);// 問題の点数
	vector<string> s(n); // 回答状況
	vector<int> kotae(n); // 答えを入れるよう
	vector<int> point(n); // 各プレイヤーの得点
	vector<vector<pair<int, char>>> kaitou(n);

	// 問題の得点入力
	rep(i, m) cin >> a[i];
	// 各プレイヤーの回答入力
	rep(i, n) cin >> s[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			kaitou[i].push_back({ a[j], s[i][j] }); // 得点と回答状況のペア
		}
	}


	// 各プレイヤーの得点計算
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'o') {
				point[i] += a[j];
			}
		}
		point[i] += (i + 1);
	}
	// 最大得点
	int max = *max_element(point.begin(), point.end());

	//sort(a.begin(), a.end(), greater<int>()); // 降順でソート


	for (int i = 0; i < n; i++) {
		vector<pair<int, char>> v;
		v = kaitou[i];
		sort(v.begin(), v.end(), desc_asc);
		int temp = point[i];

		for (int j = 0; j < m; j++) {
			if (point[i] == max) {
				break;
			}

			if (v[j].second == 'x') {
				temp += v[j].first;
				kotae[i]++;
				if (temp > max) {
					break;
				}
			}



		}
	}

	rep(i, n) {
		cout << kotae[i] << endl;
	}





	return 0;

}

