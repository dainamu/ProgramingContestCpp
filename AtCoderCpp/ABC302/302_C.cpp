#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

//int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
//int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

int main_302C() {

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	// next-permitationの前にソートする必要がある
	sort(s.begin(), s.end());

	do {
		bool ok = true;
		for(int i = 0; i<n-1; i++) {
			int d = 0;

			for (int j = 0; j < m; j++) {
			
				if (s[i][j] != s[i + 1][j]) {
					d++;
				}

			}

			//cout << "sample" << endl;
			if (d != 1) {
				ok = false;
			}

		}

		if (ok) {
			cout << "Yes" << endl;
			return 0;
		}

	} while (next_permutation(s.begin(), s.end())); // 辞書順で次の順列にする

	cout << "No" << endl;

	return 0;
}


