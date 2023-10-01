#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main_313B() {

	int n, m;
	cin >> n >> m;
	vector<int> vec(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		vec.at(b)++;
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (vec.at(i) == 0) {
			if (ans != -1) {
				cout << -1 << endl;
				exit(0);
			}
			else {
				ans = i + 1;
			}
		}
	}

	cout << ans << endl;

	return 0;
}