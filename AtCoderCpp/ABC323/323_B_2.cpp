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

	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<int> win(n);

	rep(i, n) {
		rep(j, n) {
			if (s[i][j] == 'o') win[i]++;
		}
	}

	vector<int> ans(n);
	rep(i, n) ans[i] = i;
	sort(ans.begin(), ans.end(), [&](int a, int b) ->bool {
		// 比較関数はfalseの時に要素を入れ替える
		if (win[a] == win[b]) return a < b;
		return win[a] > win[b];

		});

	rep(i, n) cout << ans[i] + 1 << ' ';
	return 0;

}

