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

	ll D;
	cin >> D;
	ll ans = D;
	ll y = 2e6 + 1;

	for (ll x = 0; x <= 2e6 + 1; x++) {

		while (y >= 0 && (x * x + y * y > D)) {
			y--;
		}

		ans = min(ans, abs(x * x + y * y - D));
		ans = min(ans, abs(x * x + (y + 1) * (y + 1) - D));
	}
	cout << ans << nl;
	return 0;

}

