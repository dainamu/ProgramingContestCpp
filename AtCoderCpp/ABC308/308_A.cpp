#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_308A() {

	vector<int> s(8);

	req(i, 8) cin >> s[i];

	int tmp = s[0];
	bool ans = true;
	for (int i = 0; i < 8; i++) {

		if (i != 0) {
			if (tmp > s[i]) {
				ans = false;
			}
			tmp = s[i];
		}

		if (s[i] < 100 || s[i] > 675) {
			ans = false;
		}

		if (s[i] % 25 != 0) {
			ans = false;
		}

		if (!ans) {
			break;
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