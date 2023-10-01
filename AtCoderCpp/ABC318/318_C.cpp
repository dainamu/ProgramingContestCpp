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

	// fをソート
	sort(f.begin(), f.end());

	// fの累積和を求めておく
	vector<ll> s(n + 1);

	rep(i, n) s[i + 1] = s[i] + f[i];

	ll ans = 1e18; // 答えを大きい数で初期化
	// 周遊パスをつかうシミュレーション
	rep(i, 1e9) { // 十分に大きい数回す

		// 小さいほうから通常料金を使うかず　dは1セットの枚数
		int r = max(0, n - i * d);

		ll now = s[r] + (ll)p * i; // sは累積和が入っている + 周遊パスの値段 * セット数
		ans = min(now, ans);

		if (r == 0) break;
	}

	cout << ans << endl;

	return 0;

}