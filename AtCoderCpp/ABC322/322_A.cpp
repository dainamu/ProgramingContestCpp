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

	int n;
	string s;

	cin >> n >> s;

	string abc = "ABC";

	for (int i = 0; i <= n - 3; i++) {

		if (abc == s.substr(i, 3)) {
			cout << i + 1 << endl;
			return 0;
		}

	}

	cout << -1 << endl;

	return 0;

}

