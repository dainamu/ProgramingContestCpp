#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;

int main_320B_2() {

	string s;

	cin >> s;

	for (int i = s.size(); i > 1; i--) { // i�𕶎����ŏ��������Ă���f�N�������g
		for (int start = 0; start + i <= s.size(); start++) { // start��0�ŏ������A�����������[�v

			string str = s.substr(start, i); // �ŏ��͕����S������
			string strR = str; // ���o�[�X�p����
			reverse(strR.begin(), strR.end()); // ����������o�[�X

			if (strR == str) {
				// ���o�[�X����������Ɣ�r
				cout << i << endl;
				return 0;
			}

		}

	}
	
	cout << 1 << endl;
	return 0;
}