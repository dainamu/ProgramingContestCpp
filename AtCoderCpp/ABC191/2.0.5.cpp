#include <iostream>
#include <vector>

using namespace std;


// �ċA�֐�
int r(vector<vector<int>> &parent, int x) {

	// �x�[�X�P�[�X
	if (parent.at(x).size() == 0) {
		return 0;
	}

	int max_time = 0;

	for (int c : parent.at(x)) {
		// �q�v�f�S�Ăɒ���

		int r_time = r(parent, c) + 1; // �񍐏��������Ă������ė��鎞���͎q�v�f�ŕ񍐏��������������{�P

		// �ǂ������傫�����A�傫���ق��������̎���
		max_time = max(max_time, r_time);

	}
	
	return max_time;
}

int main_() {

	int N;

	cin >> N;

	vector<int>  P(N);
	P.at(0) == 0;
	for (int i = 1; i < N; i++) {

		cin >> P.at(i); // i�Ԗڂ̐e�̔ԍ�
	}

	vector<vector<int>> parent(N);

	for (int i = 1; i < N; i++) {
		// �e�v�f���Ƃ̎q�v�f�̔z��
		parent.at(P.at(i)).push_back(i);
	}

	// 0�Ԗڂ̑g�D�̌��ɕ񍐏����������������߂�B
	cout << r(parent, 0) << endl;

	return 0;
}
