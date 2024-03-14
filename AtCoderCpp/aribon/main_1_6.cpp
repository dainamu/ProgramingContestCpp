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
//#include <print>
#include<stacktrace>
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


/*
 * @file ‹a–{ 1-6
 *
*/
using namespace std;
signed main_() {
	IOS;

	int n;
	cin >> n;
	vector<int> a(n);

	rep(i, n)cin >> a[i];

	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int total = a[i] + a[j] + a[k]; // Žü’·
				int max_t = max(a[i], max(a[j], a[k])); // Å‚à’·‚¢–_‚Ì’·‚³
				int rest = total - max_t;
				if (rest > max_t) {

					mx = max(mx, a[i] + a[j] + a[k]);
				}



			}
		}
	}
	cout << mx << endl;

	return 0;

}