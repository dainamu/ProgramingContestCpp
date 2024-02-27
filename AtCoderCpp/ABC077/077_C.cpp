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


signed main() {

	IOS;

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	rep(i, n)cin >> a[i];
	rep(i, n)cin >> b[i];
	rep(i, n)cin >> c[i];
	sort(ALL(a));
	sort(ALL(b));
	sort(ALL(c));
	ll ans = 0;

	rep(i, n) {

		int m = b[i];

		ll left = 0, right = n - 1;
		while (right >= left) {
			ll mid = (left + right) / 2;
			if (a[mid] < m) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		ll al = left;

		left = 0, right = n - 1;
		while (right >= left) {
			ll mid = (left + right) / 2;
			if (c[mid] <= m) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		ll bl = n - left;
		ans += (al * bl);
	}
	cout << ans << nl;

	return 0;

}

