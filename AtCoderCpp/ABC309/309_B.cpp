#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_309B() {

	int n;
	cin >> n;
	vector<string> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<string> ans;
	ans = a;

	req(i, n) {
		req(j, n) {
			if (i == 0) {
				if (j == 0) {
					ans[i][j] = a[i + 1][j];
				}
				else {
					ans[i][j] = a[i][j - 1];
				}
			}else if (i > 0 && i < n-1) {
				if (j == 0) {
					ans[i][j] = a[i + 1][j];
				}
				if (j == n - 1) {
					ans[i][j] = a[i - 1][j];
				}
			}
			else if (i == n - 1) {
				if (j == n-1) {
					ans[i][j] = a[i - 1][j];
				}
				else {
					ans[i][j] = a[i][j + 1];

				}
			}
		}
	}

	req(i, n) {
		cout << ans[i] << endl;
	}
	return 0;
}