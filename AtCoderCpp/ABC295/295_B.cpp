#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;


void boms(string, int, int, vector<vector<bool>>&); // プロトタイプ宣言

int main_295B() {

	int r, c; cin >> r >> c;

	vector<vector<string>> b(r, vector<string>(c));
	vector<vector<bool>> md(r, vector<bool>(c));

	rep(i, r) {
		string s;
		cin >> s;
		rep(j, s.length()) b[i][j] = s[j];
	}

	rep(i, r) {
		rep(j, c) {
			string s = b[i][j];
			if (s != "." && s != "#") {

				boms(s, i,j,md);

			}
		}
	}

	rep(i, r) {
		rep(j, c) {
			if (md[i][j]) {
				cout << ".";
			}
			else {

				cout << b[i][j];
			}
		}
		cout << endl;
	}
	/*rep(i, r) {
		rep(j, c) {
			cout << md[i][j];
		}
		cout << endl;
	}*/
	return 0;
}

void boms(string s, int x, int y, vector<vector<bool>> &md) {

	int power = atoi(s.c_str()); // 爆弾の威力

	for (int i = -power; i <= power; i++) {
		for (int j = -power; j <= power; j++) {
			if (abs(i) + abs(j) > power)continue;
			int nx = x + i;
			int ny = y + j;
			if (nx < 0 || nx > md[0].size() - 1 || ny < 0 || ny > md.size() - 1) continue;
			md[x + i][y + j] = true;
		}
	}


}