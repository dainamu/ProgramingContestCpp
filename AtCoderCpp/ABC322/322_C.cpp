#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#include <unordered_set>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	int n, m;

	cin >> n >> m;
	std::unordered_set<int> S;

	vector<int> a(m);
	vector<int> anss(n);
	vector<bool> is_uchiagebi(n);

	rep(i, m) {
		int temp;
		cin >> temp;
		a[i] = temp;
		S.insert(temp);
		is_uchiagebi[a[i] - 1] = true;

	}

	//rep(i, m) {
	//	is_uchiagebi[a[i]-1] = true;
	//}

	int temp = -1;
	for (int i = 0; i < n; i++) {

		//if (find(a.begin(), a.end(), i+1) != a.end()) {
		//	// 要素があれば(花火が上がる日であれば)
		//	anss[i] = 0;
		//}

		int key = i + 1;
		if (S.find(key) != S.end()) {
			anss[i] = 0;
			// tempリセット
			temp = -1;
		}
		else {

			if (temp == -1) {
				// tempがリセットされていれば再定義
				for (int j = i; j < n; j++) {
					if (is_uchiagebi[j]) {
						temp = j;
						break;
					}
				}

			}
			else {
				// tempリセットされてなければそのままつかう。
			}
			anss[i] = temp - i;


		}

	}

	rep(i, n) {
		cout << anss[i] << endl;
	}
	return 0;

}

