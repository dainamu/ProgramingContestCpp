#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_321A() {
	
	string s;
	cin >> s;

	bool ans = true;
	if (s.size() == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	for(int i = 0; i < s.size()-1; i++) {
		char c = s[i];
		char c1 = s[i+1];
		int t = c - '0';
		int t1 = c1 - '0';
		if (t <= t1) {
			ans = false;
		}
	}

	if (ans) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
