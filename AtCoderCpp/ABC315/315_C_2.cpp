#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)
using namespace std;


int main_315C_2() {

	int N;
	cin >> N;

	vector<int> F(N);
	vector<int> S(N);

	int maxS = 0;
	int choice = -1;
	
	req(i, N) {

		cin >> F[i];
		cin >> S[i];

		if (maxS < S[i]) {
			maxS = S[i];
			choice = i;
		}

	}

	int ans = 0;
	req(i, N) {

		if (i != choice) {
			int tmp;
			tmp = F[i] == F[choice] ? S[i]/2 : S[i];

			ans = max(ans, maxS + tmp);
		}

	}

	cout << ans << endl;

	return 0;
}