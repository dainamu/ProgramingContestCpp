#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main_310B() {

	int n;
	int m;

	cin >> n;
	cin >> m;

	vector<int> P(n);
	vector<vector<bool>> F(n, vector<bool>(m));

	bool ans = false;

	for (int i = 0; i < n; i++) {

		cin >> P.at(i);
		int c;
		cin >> c;
		
		for (int j = 0; j < c; j++) {
			int tmp;
			cin >> tmp;
			tmp--;
			F[i][tmp] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			// 価格
			bool b = false;
			bool b2 = true;
			bool b3 = false;
			if (P.at(i) >= P.at(j)) b = true;
			

			// 機能
			for (int k = 0; k < m; k++) {
				
				if (F[i][k] && !F[j][k]) b2 = false;
			}
			
			// j番目の製品の方が安いか、i番目にない機能をもっているか
			if (P[i] > P[j]) b3 = true;
			
			for (int k = 0; k < m; k++) {

				if (!F[i][k] && F[j][k]) b3 = true;
			}


			if (b && b2 && b3) ans = true;
		}

	}

	if (ans == true) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}