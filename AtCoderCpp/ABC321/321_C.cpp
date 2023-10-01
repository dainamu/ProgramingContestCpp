#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

using ll = long long;

int main_321C() {

	int k;
	cin >> k;

	vector<ll> a; // 321like Numberを格納する用の配列

	rep(s, 1 << 10) { // 1<<10 は2の10乗

		ll x = 0; // 321like Number用の変数

		for (int i = 9; i >= 0; i--) { // 9,8,7,6,5,4,3,2,1,0
			if (s >> i & 1) { // i桁目に1が立っている場合
				x = x * 10 + i;

			}
		}

		if (x == 0) {

			/*
			xxxxxxxxxx ＝ 部分集合が空（どの数字も使わない）の場合除外
			xxxxxxxxxo ＝ 0は321likenumberではないの除外
			9876543210
			*/
			continue;
		}
		a.push_back(x); // 作った321like Numberを格納する
	}


	// 確認用star
	cout << "ソート前" << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	// end


	sort(a.begin(), a.end());
	// 確認用start
	cout << "ソート後" << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	// end

	cout << a[k - 1] << endl;

	return 0;
}

