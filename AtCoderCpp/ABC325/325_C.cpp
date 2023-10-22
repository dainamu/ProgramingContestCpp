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
#include <bitset>
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

using namespace std;
using P = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

using P = pair<int, int>;

signed main() {


	ios::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	vector<string> s(h);
	rep(i, h) {
		cin >> s[i];
	}

	vector<vector<bool>>  t(h, vector<bool>(w));
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {

			auto f = [&](auto f, int xi, int xj)->void {

				// なにもなければ　リターン
				if (s[xi][xj] == '.')return;
				// 判定済みの場合リターン
				if (t[xi][xj]) return;

				if (s[xi][xj] == '#') {

					t[xi][xj] = true;
					for (int k = 0; k < 9; k++) {
						if (xi + di[k]<0 || xi + di[k] > h - 1)continue;
						if (xj + dj[k]<0 || xj + dj[k] > w - 1)continue;

						f(f, xi + di[k], xj + dj[k]);
					}

				}
				ans++;

				};
			if (!t[i][j] && s[i][j] == '#') {
				f(f, i, j);

			}
		}
	}
	cout << ans << endl;
	return 0;

}

