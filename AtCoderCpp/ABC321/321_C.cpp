#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

using ll = long long;

int main_321C() {

	int k;
	cin >> k;

	vector<ll> a; // 321like Number���i�[����p�̔z��

	rep(s, 1 << 10) { // 1<<10 ��2��10��

		ll x = 0; // 321like Number�p�̕ϐ�

		for (int i = 9; i >= 0; i--) { // 9,8,7,6,5,4,3,2,1,0
			if (s >> i & 1) { // i���ڂ�1�������Ă���ꍇ
				x = x * 10 + i;

			}
		}

		if (x == 0) {

			/*
			xxxxxxxxxx �� �����W������i�ǂ̐������g��Ȃ��j�̏ꍇ���O
			xxxxxxxxxo �� 0��321likenumber�ł͂Ȃ��̏��O
			9876543210
			*/
			continue;
		}
		a.push_back(x); // �����321like Number���i�[����
	}


	// �m�F�pstar
	cout << "�\�[�g�O" << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	// end


	sort(a.begin(), a.end());
	// �m�F�pstart
	cout << "�\�[�g��" << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
	// end

	cout << a[k - 1] << endl;

	return 0;
}

