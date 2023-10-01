#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;

int main_313C() {

	int n;

	cin >> n;
	vector<int> a(n);

	ll sum = 0;

	req(i, n) {
		
		cin >> a[i];
		sum += a[i];
	}

	sort(a.begin(), a.end());
	vector<int> b(n, sum / n);
	for (int i = 0; i < sum % n; i++) {
		b[n - 1 - i]++;
	}
	ll ans = 0;
	req(i, n) ans += abs(a[i] - b[i]);

	cout << ans / 2 << "\n";

	return 0;
}