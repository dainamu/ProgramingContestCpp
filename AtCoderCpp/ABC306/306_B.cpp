#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	ull ans = 0; // unsignedで符号なしのため、64ビットフルにつかえる。そのかわりマイナスの値は使えない。

	rep(i, 64) {
		ull a;
		cin >> a;
		ans += a << i; // i桁シフト 0だったら0、1だったら、2のi乗
	}

	cout << ans;
	return 0;

}

