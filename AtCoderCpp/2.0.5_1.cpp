#include <iostream>
#include <vector>
using namespace std;


// �������ړ����𒲂ׂ�iy�Ax�j���ړ���
bool is_valid_move(vector<string>& board, vector<vector<bool>>& checked, int x, int y) {
	
	int N = board.size();

	// �ړ��悪�}�X�ڂ̊O�ł���ꍇ
	if (x <= -1 || x >= N || y <= -1 || y >= N) {
		return false;
	}

	// �ړ��悪��
	if (board.at(y).at(x) == '#') {

		return false;
	}

	// ���łɒ��ׂĂ���}�X�ւ̈ړ��͒��ׂȂ��̂�false
	if (checked.at(y).at(x)) {
		return false;

	}

	// ����ȊO�͐������ړ�
	return true;

}

// (y, x) �ɂ����Ԃ���S�[���ɓ��B�ł��邩
// board: �}�X�ڂ̎��
// checked: ���̃}�X�����łɒ��ׂ��������񎟌��z��
bool reachable(vector<string>& board, vector<vector<bool>>& checked, int x, int y) {

	int N = board.size();

	// �x�[�X�P�[�X
	if (x == N - 1 && y == N - 1) {
		return true;
	}

	// �ċA�X�e�b�v
	checked.at(y).at(x) = true; // ���łɒ��ׂĂ����Ԃ��Ă���

	// �u��v�u�E�v�u���v�u���v�̂����ꂩ�̈ړ��ŃS�[���ɓ��B�ł��邩�H
	bool result = false;

	// ��ֈړ������}�X����S�[���ɓ��B�ł��邩�H
	if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) {
		result = true;
	}

	//  ���ֈړ������}�X����S�[���ɓ��B�ł��邩�H
	if (is_valid_move(board, checked, x-1, y) && reachable(board, checked, x - 1, y)) {
		result = true;
	}

	// ���ֈړ������}�X����S�[���ɓ��B�ł��邩�H
	if (is_valid_move(board, checked, x, y+1) && reachable(board, checked, x, y+1)) {
		result = true;
	}
	// �E�ֈړ������}�X����S�[���ɓ��B�ł��邩�H
	if (is_valid_move(board, checked, x+1, y) && reachable(board, checked, x+1, y)) {
		result = true;
	}

	return result;

}


int main_2051() {
	// �����̔z���ω��������
	
	int N;

	cin >> N;

	vector<string> board(N);

	for (int i = 0; i < N; i++) {
		cin >> board.at(i);
	}

	// ���łɂ��̃}�X�𒲂ׂ�����ێ�����񎟌��z��
	vector<vector<bool>> checked(N, vector<bool>(N, false)); // �����lfalse

	// (0, 0) ����S�[���֓��B�ł��邩
	if (reachable(board, checked, 0, 0)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}