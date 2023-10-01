#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

int main() {


	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(4));
	rep(i, n) {
		rep(j, 4) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> M(100, vector<int>(100));

	rep(i, n) {

		for (int j = a[i][0]; j < a[i][1]; j++) {
			for (int k = a[i][2]; k < a[i][3]; k++) {

				M[k][j] = 1;

			}

		}

	}

	int ans = 0;
	rep(i, 100)rep(j, 100) {
		if (M[i][j] == 1) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;

}