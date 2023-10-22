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


int sum(int n) {

	if (n == 0) {
		return 0;
	}

	int s = sum(n - 1);

	int total = s + n;

	return total;



}


signed main() {

	int n;
	cin >> n;

	// 0‚©‚çn‚Ü‚Å‚Ì‘˜a
	int val;
	val = sum(n);

	cout << val << endl;

}

