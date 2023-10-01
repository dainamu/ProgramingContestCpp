#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

int main() {

	int n, d, p;
	cin >> n >> d >> p;
	vector<int> f(n);

	rep(i, n) cin >> f[i];

	// 累積和用
	vector<ll> s(n + 1);
	rep(i, n) s[i + 1] = s[i] + f[i];

	ll ans = 1e18; // 基数10の累乗






	return 0;

}