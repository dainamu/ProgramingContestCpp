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
#include <queue>
//#include <format>
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const char nl = '\n';
using namespace std;
using P = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

//int dx[] = { -1,0,1, 0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
//int dy[] = { 0 ,1,0,-1, 1,1,-1,-1,0 };

int dx[] = { 1,0, -1, 0,-1,1,1,-1,0 }; // « ¨ ª ©
int dy[] = { 0,1, 0 ,-1, 1,1,-1,-1,0 };

struct state {
	int x, y, dir;
};

signed main() {

	IOS;

	int n;
	string s;
	cin >> n >> s;

	int ans = 0;
	vector<int> mx(26);

	vector<pair<char, int>> d;
	d.emplace_back(s[0], 0);

	for (char c : s) {

		if (d.back().first == c) {
			d.back().second++;
		}
		else {
			d.emplace_back(c, 1);
		}


	}

	for (auto [c, len] : d) {
		mx[c - 'a'] = max(mx[c - 'a'], len);
	}

	for (auto e : mx) {
		ans += e;
	}
	cout << ans << nl;
	return 0;
}

