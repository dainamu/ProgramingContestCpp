#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_308B() {

	int n, m;
	cin >> n >> m;
	vector<string> c(n);
	vector<string> d(m);
	vector<int> p(m);
	int athar = 0;

	req(i, n) cin >> c[i];
	req(i, m) cin >> d[i];
	for(int i = 0; i<m+1; i++){

		if (i == 0) {
			cin >> athar;
		}
		else {

			cin >> p[i-1];
		}
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		int tmp = -1;
		for (int j = 0; j < m; j++) {
			
			if (c[i] == d[j]) {
				tmp = j;
			}
		}
		if (tmp == -1) {
			total += athar;
		}
		else {
			total += p[tmp];
		}
	}

	cout << total << endl;

	return 0;
}