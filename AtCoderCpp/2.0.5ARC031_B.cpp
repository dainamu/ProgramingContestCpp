#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;

void isIsland(vector<string> a, vector<vector<bool>> &isChecked, int x, int y) {

	
	// �`�F�b�N�ς݂̏ꍇ�A���^�[��
	if (isChecked.at(x).at(y)) {
		return;
	}
	
	// ���݂̃}�X���`�F�b�N�ς݂ɂ���
	isChecked.at(x).at(y) = true;

	// ���݂̃}�X�̏��
	char c =  a.at(x).at(y);

	if (c == '-' || c == 'x') {
		// ���n�ȊO�̏ꍇ
		return;
	}



	// �㉺���E�ɑ΂��ČĂяo��
	isIsland(a, isChecked, x + 1, y);
	isIsland(a, isChecked, x - 1, y);
	isIsland(a, isChecked, x, y+1);
	isIsland(a, isChecked, x, y-1);

	


}

int main() {

	vector<string> a(12);

	a.at(0) = "------------";
	a.at(11) = "------------";
	for(int i = 1; i<11; i++){

		string tmp;
		cin >> tmp;
		tmp = '-' + tmp + '-';

		a.at(i) = tmp;
	}

	// �܂����ׂĂ̗��n�܂����Ȃ����Ă��邩�𒲂ׂ�֐�
	// ���ׂĂ̗��n���Ȃ����Ă��遨����ЂƂ̗��n�܂�����㉺���E�̈ړ����J��Ԃ��āA�S�Ă̗��n�ɂ��ǂ����B


	// ���n�}�X����T��
	int x, y;
	bool ans = true;
	// �S�Ẵ}�X�𖄂ߗ��Ă�ΏۂƂ���1�̓��ɂȂ邩
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			char tmp = a.at(i).at(j);
			a.at(i).at(j) = 'o';// ���n�ɂ���

			// �ċA�֐����Ăяo����isChecked�𖄂߂�
			// �`�F�b�N�p�z��
			vector<vector<bool>> isChecked(12, vector<bool>(12, false));
			isIsland(a, isChecked, i, j);

			// ���n���ׂĂ��`�F�b�N���݂ł���Έ�̂���

			for (int i = 1; i < 11; i++) {
				for (int j = 1; j < 11; j++) {
					if (a.at(i).at(j) == 'o') {
						if (isChecked.at(i).at(j) == false) {
							// ���n���`�F�b�N�ł��Ă��Ȃ��B
							ans = false;
						}
					}
				}
			}

			if (ans) {
				goto exit;
			}
			a.at(i).at(j) = tmp;// �}�X�����ɂ��ǂ�


		}

	}


exit:
	cout << (ans ? "YES" : "NO") << endl;

	return 0;
}