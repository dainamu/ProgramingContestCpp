#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_312_B_2() {

	int n, x;
	cin >> n >> x;

	vector<int> a(n); 
	rep(i, n - 1) cin >> a[i]; // �Ō�̗v�f�͓��͂��ĂȂ���vector�̏����l0�ŏ���������Ă���B

	while (a.back() <= 100) {
		vector<int> b = a; // a�̔z�񂪃R�s�[�����
		sort(b.begin(), b.end()); // b���\�[�g���Ă�a�͂��̂܂�
		int s = 0;
		for (int i = 1; i < n - 1; i++) s += b[i]; // �擪�Ɩ��������������a

		if (s >= x) {
			cout << a.back() << endl;
			return 0;
		}

		a.back()++; // �����̗v�f���C���N�������g
	}

	// �����܂ł���������𖞂������Ƃ͂ł��Ȃ��̂ŁA-1���o��
	cout << -1 << endl;

	return 0;
}

/*

�ڈ��FTLE�̖ڈ�10��8��ȉ�

�E�܂��͑S�T���ł��Ȃ���
*/