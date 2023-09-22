#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_317A() {

	int n, h, x;

	cin >> n >> h >> x;

	vector<int> p(n);

	req(i, n) cin >> p.at(i);

	for (int i = 0; i < n; i++) {
		int total;
		total = h + p.at(i);
		if (total >= x) {

			cout << i + 1 << endl;
			break;
		}
	}

	return 0;
}