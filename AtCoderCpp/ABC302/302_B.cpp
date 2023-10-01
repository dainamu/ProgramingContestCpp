#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;

void print_ans(string, int, int, int);

bool is_snuke(string);

int main_302B() {


	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	
	rep(i, h) cin >> s[i];

	for (int i = 0; i < h; i++) {

		for (int k = 0; k+4 < w; k++) {
			if (k + 4 > w -1)break;
			string temp = "";
			for (int j = 0; j < 5; j++) {
				if (j + k > s[i].length()-1) {
					break;
				}
				
				temp.push_back(s[i][k + j]);

			}
			if (is_snuke(temp)) {
				print_ans(temp, i, k, 1);
				return 0;
			}
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j + 4 < h; j++) {
			string temp = "";
			for (int k = 0; k < 5; k++) {
				
				temp.push_back(s[j+k][i]);
			}
			if (is_snuke(temp)) {
				print_ans(temp, j, i, 2);
				return 0;
			}
		}
	}

	for (int i = 0; i+4 < h; i++) {
		for (int j = 0; j+4 < w; j++) {
			string temp = "";
			for (int k = 0; k < 5; k++) {

				temp.push_back(s[i+k][j+k]);
			}
			if (is_snuke(temp)) {
				print_ans(temp, j, i, 3);
				return 0;
			}
		}
	}


	return 0;
}

void print_ans(string temp, int h, int w, int mode) {

	if (temp == "snuke" && mode == 1) {

		for (int l = 0; l < 5; l++) {
			cout << h + 1 << " " << w + l + 1 << endl;
		}

	}
	else if (temp == "ekuns" && mode == 1) {
		int u = w + 1 + 4;
		for (int l = 0; l < 5; l++) {
			cout << h + 1 << " " << u-l << endl;
		}
	}

	if (temp == "snuke" && mode == 2) {

		for (int l = 0; l < 5; l++) {
			cout << h + l +1 << " " << w + 1 << endl;
		}

	}
	else if (temp == "ekuns" && mode == 2) {
		int u = h + 1 +4;
		for (int l = 0; l < 5; l++) {
			cout << u - l << " " << w + 1 << endl;
		}
	}

	if (temp == "snuke" && mode == 3) {

		for (int l = 0; l < 5; l++) {
			cout << h + l + 1 << " " << w + l +1 << endl;
		}

	}
	else if (temp == "ekuns" && mode == 3) {
		int u = h + 1 + 4; int t = w + 1 + 4;
		for (int l = 0; l < 5; l++) {
			cout << u - l << " " << t - l << endl;
		}
	}
}

bool is_snuke(string s) {

	return s == "snuke" || s == "ekuns";
}