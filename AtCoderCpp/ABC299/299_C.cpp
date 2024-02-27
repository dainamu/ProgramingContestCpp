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
#include <numeric>
//#include <format>
#include <stack>
#include <regex>
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const char nl = '\n';
const int INF = 102345678;
using namespace std;
using P = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dx[] = { -1,0,1, 0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dy[] = { 0 ,1,0,-1, 1,1,-1,-1,0 };

//int dx[] = { 1,0, -1, 0,-1,1,1,-1,0 }; // « ¨ ª ©
//int dy[] = { 0,1, 0 ,-1, 1,1,-1,-1,0 };

signed main() {
	IOS;

	int n;
	string s;
	cin >> n >> s;
	vector<int> cnt;

	bool flg = false;
	for (int i = 0; i < n; i++) {


		if (s[i] == 'o') {
			if (!flg) {
				cnt.push_back(0);
			}
			cnt.back()++;
			flg = true;
		}
		else {
			flg = false;
		}
	}

	if (find(s.begin(), s.end(), '-') != s.end()) {
		// Œ©‚Â‚©‚Á‚½‚Î‚ ‚¢
		if (cnt.size() == 0) {
			cout << -1 << nl;
		}
		else {
			int ans = *max_element(cnt.begin(), cnt.end());
			cout << ans << nl;
		}
	}
	else {
		cout << -1 << nl;
	}



	return 0;
}


