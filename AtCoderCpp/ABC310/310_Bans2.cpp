#include <iostream>
#include <vector>

using namespace std;

int main_310Bans2() {

	int N;
	int M;

	cin >> N >> M;
	
	vector<int> P(N);
	vector<vector<bool>> func(N, vector<bool>(M)); // func[i][j]:i�Ԗڂ̏��i��j�ԉ~�̋@�\������

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int f;
			cin >> f;
			f--; // 0�C���f�b�N�X
			func[i][f] = true;


		}
	}

	bool ans = false; // ���������ׂĖ����� (i,j)�̃y�A�����݂��邩
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool cond1 = false; // P_i >= P_j ���ǂ���
			bool cond2 = true; // j�Ԗڂ̐��i��i�Ԗڂ̐��i�����@�\�����ׂĎ���
			bool cond3 = false; // P_i>P_j�ł���A�܂��́Aj�Ԗڂ̐��i��i�Ԗڂ̐��i�ɂȂ��@�\������

			if (P[i] >= P[j]) cond1 = true;

			for (int k = 0; k < M; k++) {
				if (func[i][k] && !func[j][k]) cond2 = false;
			}

			if (P[i] > P[j]) cond3 = true;
			for (int k = 0; k < M; k++) {
				if (!func[i][k] && func[j][k]) cond3 = true;
			}

			if (cond1 && cond2 && cond3) ans = true;



		}
	}



	if (ans == true) cout << "Yes" << endl;
	else cout << "No" << endl;


	return 0;
}