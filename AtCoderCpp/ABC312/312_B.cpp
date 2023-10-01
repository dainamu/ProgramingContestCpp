#include <iostream>
#include <vector>

using namespace std;

int main_312B() {

	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> ans;
	vector<string> s(n);
	vector<string> code{
		{"###.-----" },
		{"###.-----" },
		{"###.-----" },
		{"....-----" },
		{"---------" },
		{"-----...." },
		{"-----.###" },
		{"-----.###" },
		{"-----.###" },
		{"-----.###" }
	};
	for (auto &str : s) cin >> str;

	for (int i = 0; i < (n-8); i++) {
		for (int j = 0; j < (m-8); j++) {
			int tmp = 0;
			for (int k = 0; k < 9; k++) {
				for (int l = 0; l < 9; l++) {

					if (code[k][l] == '-') {

					}
					else {
						if (s[i + k][j + l] == code[k][l]) {
							tmp++;
						}
						else {
							goto BREAK_LABEL;
						}
					}
				}

			}
		BREAK_LABEL:
			if (tmp == 32) {
				vector<int> a(2);
				a[0] = i;
				a[1] = j;
				ans.push_back(a);
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i][0]+1 << " " << ans[i][1]+1 << endl;
	}
	return 0;
}