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
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()


using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	vector<string> s(n);
	// 入力受付
	rep(i, m) cin >> a[i];
	rep(i, n) cin >> s[i];

	// 各プレイヤーの得点計算
	vector<int> point(n);
	rep(i, n) {
		point[i] += i + 1; // ボーナス
		rep(j, m) {
			if (s[i][j] == 'o') point[i] += a[j];
		}
	}
	// 最大得点取得
	int maxPoint = *max_element(ALL(point));


	for (int i = 0; i < n; i++) {
		vector<int> r; // 余っている問題の配列

		rep(j, m) {
			if (s[i][j] == 'x') {
				r.push_back(a[j]);
			}

		}
		// 昇順でソート
		if (r.size() >= 1) {
			sort(ALL(r));
		}
		int ans = 0;
		while (point[i] < maxPoint) {
			point[i] += r.back(); // 一番後ろの要素を取得
			r.pop_back(); // 一番後ろの要素を削除
			ans++;
		}

		cout << ans << endl;

	}

	return 0;

}

