#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;

void fill_island(vector<string> borad, vector<vector<bool>> &isChecked, int x, int y) {

	// ��O�̏ꍇ�̓��^�[��
	if (x < 0 || x > 9 || y < 0 || y>9) return;
	// �`�F�b�N�ς݂̏ꍇ�A���^�[��
	if (isChecked.at(x).at(y)) {
		return;
	}
	
	// ���݂̃}�X���`�F�b�N�ς݂ɂ���
	isChecked.at(x).at(y) = true;

	if (borad[x][y] == 'x') {
		// �C�̏ꍇ
		return;
	}



	// �㉺���E�ɑ΂��ČĂяo��
	fill_island(borad, isChecked, x + 1, y);
	fill_island(borad, isChecked, x - 1, y);
	fill_island(borad, isChecked, x, y+1);
	fill_island(borad, isChecked, x, y-1);

}

bool check_connected(vector<string> board, int x, int y) {

	// �`�F�b�N�p�z��
	vector<vector<bool>> isChecked(10, vector<bool>(10, false));

	// �ċA�֐���isChecked������������
	fill_island(board, isChecked, x, y);

	bool ans = true;
	req(i, 10) {
		req(j, 10) {
			if (board[i][j] == 'o') {
				// ���n�Ń`�F�b�N����Ă��Ȃ����NG
				if (isChecked[i][j] == false) {
					ans = false;
				}
			}
		}
	}

	return ans;

}

int main_ARC031_B() {

	vector<string> board(10);

	req(i, 10) cin >> board[i];

	bool ans = true;

	// �S�Ẵ}�X�𖄂ߗ��Ă�ΏۂƂ���1�̓��ɂȂ邩
	req(i, 10){
		req(j, 10){

			if (board.at(i).at(j) == 'o') continue;

			char tmp = board.at(i).at(j); // �������̃}�X��ޔ�
			board.at(i).at(j) = 'o';// ���n�ɂ���

			if (check_connected(board, i, j)) {
				cout << "YES" << endl;
				return 0;
			}

			board.at(i).at(j) = tmp;// �}�X�����ɂ��ǂ�


		}

	}

	cout << "NO" << endl;
	return 0;
}