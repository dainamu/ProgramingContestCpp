#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;

	string maeN;
	string ushiroN;

	maeN = t.substr(0, n);
	ushiroN = t.substr(t.length() - n, n);

	/*cout << maeN << endl;
	cout << ushiroN << endl;*/


	if (maeN == s && ushiroN == s) {
		cout << 0 << endl;
	}
	else if (maeN == s) {
		cout << 1 << endl;
	}
	else if (ushiroN == s) {
		cout << 2 << endl;
	}
	else {
		cout << 3 << endl;
	}

	return 0;

}

