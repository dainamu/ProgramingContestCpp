#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_321B() {
	
	int n, x;
	cin >> n >> x;

	vector<int> a;
	int max = 0;
	rep(i, n - 1) {
		int tmp;
		max = std::max(max, tmp);
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	vector<int> tm = a;
	vector<int> tx = a;
	vector<int> th = a;

	tm.insert(tm.begin(), 0);
	tx.push_back(a[n-2]+1);

	int mid = 0;
	rep (i, a.size()) {
		if (i != 0 && i != a.size() - 1) {
			mid += a[i];
		}
	}
	mid = x - mid;
	
	int tm_v = 0;
	int tx_v = 0;
	int th_vv = 0;

	rep(i, tm.size()) {
		
		if (i != 0 && i != tm.size() - 1) {
			tm_v += tm[i];
			tx_v += tx[i];
		}

	}
	bool th_b = true;
		rep(i, th.size()) {
			if (i != 0 && i != th.size() - 1) {
	
				th_vv += th[i];
			}
		}



	th_vv += mid;

	bool tm_b = false;
	bool tx_b = false;
	
	int ans = 1001001;
	if (tm_v >= x) {
		tm_b = true;
		ans = min(0, ans);
	}
	if (tx_v >= x) {
		tx_b = true;
		ans = min(tx[tx.size() - 1], ans);
	}
	if (mid < 0) { th_b == false; }
	if (th_b && th_vv >= x) {
		th_b = true;
		ans = min(ans, mid);
	}
	if (ans == 1001001) {
		ans = -1;
	}
	cout << ans << endl;
	

	return 0;
}
