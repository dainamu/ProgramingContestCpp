#include <iostream>
#include <vector>

using namespace std;

int main_310Bans2() {

	int N;
	int M;

	cin >> N >> M;
	
	vector<int> P(N);
	vector<vector<bool>> func(N, vector<bool>(M)); // func[i][j]:i番目の商品がj番円の機能を持つか

	for (int i = 0; i < N; i++) {
		cin >> P[i];
		int c;
		cin >> c;
		for (int j = 0; j < c; j++) {
			int f;
			cin >> f;
			f--; // 0インデックス
			func[i][f] = true;


		}
	}

	bool ans = false; // 条件をすべて満たす (i,j)のペアが存在するか
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool cond1 = false; // P_i >= P_j かどうか
			bool cond2 = true; // j番目の製品がi番目の製品が持つ機能をすべて持つか
			bool cond3 = false; // P_i>P_jである、または、j番目の製品がi番目の製品にない機能をもつか

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