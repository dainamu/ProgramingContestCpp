#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main_310A() {

	long n;
	long p;
	long q;

	

	cin >> n;
	cin >> p;
	cin >> q;

	vector<long> d(n);
	int ans;

	for (int i = 0; i < n; i++) {
		cin >> d.at(i);
	}

	ans = p;
	for (int i = 0; i < n; i++) {
		int tmp;
		tmp = q + d.at(i);
		ans = min(tmp, ans);
	}

	cout << ans << endl;

	return 0;
}