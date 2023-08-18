#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main_313A() {

	int n;
	


	cin >> n;
	int ans = 0;
	vector<int> p(n);
	for (auto& val : p) {
		cin >> val;
	}

	int first = p.at(0);
	for (int i = 1; i < n; i++) {
		int tmp = first - p.at(i);
		if (tmp <= 0) {
			
			ans = max(ans, -tmp + 1);
		}
	}

	cout << ans << endl;
	




	return 0;
}