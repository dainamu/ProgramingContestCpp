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

	int n, x;
	cin >> n >> x;

	vector<int> a(n - 1);
	rep(i, n - 1) cin >> a[i];

	rep(i, 101) {

		vector<int> v;
		v = a;
		v.push_back(i);
		sort(ALL(v));

		int temp = 0;
		for (int j = 0; j < n; j++) {
			if (j == 0 || j == n - 1)continue;
			temp += v[j];

		}
		if (temp >= x) {
			cout << i << endl;
			return 0;
		}

	}

	cout << -1 << endl;
	return 0;

}

