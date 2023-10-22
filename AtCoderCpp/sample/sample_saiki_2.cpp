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
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	int n;
	cin >> n;

	// n‚ÌŠKæ
	auto f = [&](auto f, int n)->int {
		if (n == 1) {
			return 1;
		}

		return n * f(f, n - 1);

		};
	int ans = f(f, n);
	cout << ans << endl;


	return 0;

}

