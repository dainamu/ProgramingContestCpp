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
#include <bitset>
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

using namespace std;
using P = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	vector<int> c(9);
	rep(i, 9)cin >> c[i];
	vector<int> p(9);
	rep(i, 9)p[i] = i;
	int cnt = 0, tot = 0;
	vector<vector<int>> bingo{
							   {0,1,2},{3,4,5},{6,7,8},
							   {0,3,6},{1,4,7},{2,5,8},
							   {0,4,8 },{2,4,6}
	};
	do {
		bool ok = true;

		auto f = [&](int i, int j, int k)->void {
			// �e�񂪓��͂����̂ŁA�������肩����
			vector<P> vec;
			vec.emplace_back(p[i], c[i]);
			vec.emplace_back(p[j], c[j]);
			vec.emplace_back(p[k], c[k]);
			sort(ALL(vec)); // 1�ڂ̗v�f�̏����i�I�΂�鏇�Ƀ\�[�g�j

			if (vec[0].second == vec[1].second) {
				ok = false;
			}

			};

		// �c�A���A�΂߂𔻒�
		for (int i = 0; i < bingo.size(); i++) {
			f(bingo[i][0], bingo[i][1], bingo[i][2]);
		};


		if (ok)cnt++;

		tot++;

	} while (next_permutation(ALL(p)));

	double ans = 1. * cnt / tot; // 1.�ŏ����double�^�ɂȂ�
	//cout << ans << endl;
	printf("%.10f\n", ans);
	return 0;

}

