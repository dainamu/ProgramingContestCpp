#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

//int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
//int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

int main_302C() {

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	// next-permitation�̑O�Ƀ\�[�g����K�v������
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

	} while (next_permutation(s.begin(), s.end())); // �������Ŏ��̏���ɂ���

	cout << "No" << endl;

	return 0;
}


