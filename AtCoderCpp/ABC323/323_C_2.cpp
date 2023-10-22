#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#include <compare>
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()


using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	vector<string> s(n);
	// ���͎�t
	rep(i, m) cin >> a[i];
	rep(i, n) cin >> s[i];

	// �e�v���C���[�̓��_�v�Z
	vector<int> point(n);
	rep(i, n) {
		point[i] += i + 1; // �{�[�i�X
		rep(j, m) {
			if (s[i][j] == 'o') point[i] += a[j];
		}
	}
	// �ő哾�_�擾
	int maxPoint = *max_element(ALL(point));


	for (int i = 0; i < n; i++) {
		vector<int> r; // �]���Ă�����̔z��

		rep(j, m) {
			if (s[i][j] == 'x') {
				r.push_back(a[j]);
			}

		}
		// �����Ń\�[�g
		if (r.size() >= 1) {
			sort(ALL(r));
		}
		int ans = 0;
		while (point[i] < maxPoint) {
			point[i] += r.back(); // ��Ԍ��̗v�f���擾
			r.pop_back(); // ��Ԍ��̗v�f���폜
			ans++;
		}

		cout << ans << endl;

	}

	return 0;

}

