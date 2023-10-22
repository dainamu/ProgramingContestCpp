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

	bitset<16> a("0101010101010101");
	string c;
	cin >> c;

	bitset<16> b(c);

	if ((a & b) == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;

}

