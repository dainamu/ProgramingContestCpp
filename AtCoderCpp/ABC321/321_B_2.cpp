#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_312_B_2() {

	int n, x;
	cin >> n >> x;

	vector<int> a(n); 
	rep(i, n - 1) cin >> a[i]; // 最後の要素は入力してないがvectorの初期値0で初期化されている。

	while (a.back() <= 100) {
		vector<int> b = a; // aの配列がコピーされる
		sort(b.begin(), b.end()); // bをソートしてもaはそのまま
		int s = 0;
		for (int i = 1; i < n - 1; i++) s += b[i]; // 先頭と末尾を除いた総和

		if (s >= x) {
			cout << a.back() << endl;
			return 0;
		}

		a.back()++; // 末尾の要素をインクリメント
	}

	// ここまできたら条件を満たすことはできないので、-1を出力
	cout << -1 << endl;

	return 0;
}

/*

目安：TLEの目安10の8乗以下

・まずは全探索できないか
*/