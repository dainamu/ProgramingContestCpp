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

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

struct Edge {

};

signed main() {

	IOS;

	int n, d;
	cin >> n >> d;
	vector<P> g(n);
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		g[i].first = x;
		g[i].second = y;

	}
	vector<vector<int>> eg(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			int x1, x2, y1, y2;
			x1 = g[i].first;
			y1 = g[i].second;
			x2 = g[j].first;
			y2 = g[j].second;

			double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

			if (dist <= d) {
				eg[i].push_back(j);
			}


		}
	}
	vector<bool> isPositive(n);
	isPositive[0] = true;
	for (int i = 0; i < eg[0].size(); i++) {

		auto f = [&](auto f, int to)->void {

			if (isPositive[to]) {
				return;
			}
			isPositive[to] = true;
			for (int j = 0; j < eg[to].size(); j++) {
				f(f, eg[to][j]);
			}
			};

		f(f, eg[0][i]);
	}
	for (int i = 0; i < n; i++) {
		cout << (isPositive[i] ? "Yes" : "No") << nl;
	}
	return 0;

}

