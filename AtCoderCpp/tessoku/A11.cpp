#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };


signed main() {

	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	int wa = 0;
	int ac = a.size();
	while (abs(ac - wa) > 1) {
		int wj = (ac + wa) / 2;
		if (a[wj] == x) {
			ac = wj;
			break;
		}

		if (x > a[wj]) {
			wa = wj;
		}
		else {
			ac = wj;
		}

	}

	++ac;
	cout << ac << endl;

	return 0;

}

