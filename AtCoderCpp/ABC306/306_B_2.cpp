#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	ull ans = 0;
	int n = 64;
	vector<int> a(n);
	rep(i, n) {

		cin >> a[i];
	}

	rep(i, n) {


		if (a[i] == 1) {
			ull temp = std::pow(2, i);
			ans += temp;
			//cout << "2の" << i << "乗：" <<  temp << "  ans:" << ans << endl;

		}
	}

	cout << ans;
	return 0;

}

