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

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

using P = pair<int, int>;
signed main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto& e : a)cin >> e;
	sort(ALL(a));
	int res = 0;
	int t, s;
	s = t = 0;
	for (;;) {

		while (t < n && a[t] < a[s] + m) {
			t++;
		}
		res = max(res, t - s);
		s++;

		if (s >= n)break;

	}

	cout << res << endl;



	return 0;



}

