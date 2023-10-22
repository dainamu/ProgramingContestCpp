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

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

bool desc_asc(pair<int, char>& left, pair<int, char>& right) {
	if (left.first == right.first) {
		return left.second < right.second;
	}
	else {
		return right.first < left.first;
	}
}

signed main() {


	int n, m; // n �v���C���[�� m ��萔
	cin >> n >> m;

	vector<int> a(m);// ���̓_��
	vector<string> s(n); // �񓚏�
	vector<int> kotae(n); // ����������悤
	vector<int> point(n); // �e�v���C���[�̓��_
	vector<vector<pair<int, char>>> kaitou(n);

	// ���̓��_����
	rep(i, m) cin >> a[i];
	// �e�v���C���[�̉񓚓���
	rep(i, n) cin >> s[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			kaitou[i].push_back({ a[j], s[i][j] }); // ���_�Ɖ񓚏󋵂̃y�A
		}
	}


	// �e�v���C���[�̓��_�v�Z
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'o') {
				point[i] += a[j];
			}
		}
		point[i] += (i + 1);
	}
	// �ő哾�_
	int max = *max_element(point.begin(), point.end());

	//sort(a.begin(), a.end(), greater<int>()); // �~���Ń\�[�g


	for (int i = 0; i < n; i++) {
		vector<pair<int, char>> v;
		v = kaitou[i];
		sort(v.begin(), v.end(), desc_asc);
		int temp = point[i];

		for (int j = 0; j < m; j++) {
			if (point[i] == max) {
				break;
			}

			if (v[j].second == 'x') {
				temp += v[j].first;
				kotae[i]++;
				if (temp > max) {
					break;
				}
			}



		}
	}

	rep(i, n) {
		cout << kotae[i] << endl;
	}





	return 0;

}

