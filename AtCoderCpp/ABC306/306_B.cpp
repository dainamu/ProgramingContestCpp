#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	ull ans = 0; // unsigned�ŕ����Ȃ��̂��߁A64�r�b�g�t���ɂ�����B���̂����}�C�i�X�̒l�͎g���Ȃ��B

	rep(i, 64) {
		ull a;
		cin >> a;
		ans += a << i; // i���V�t�g 0��������0�A1��������A2��i��
	}

	cout << ans;
	return 0;

}

