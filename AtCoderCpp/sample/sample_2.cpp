#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;


int main_sample_2() {

	vector<string> floor{ "###########","###########","###########","###########","###########","###########",
						  "###########","###########","###########","###########","###########" };

	for (int i = -3; i <= 3; i++) {
		for (int j = -3; j <= 3; j++) {
			if (abs(i) + abs(j) > 3)continue;
			floor[5 + i][5 + j] = 'x';
		}
	}

	
	rep(i, floor.size()) {
		cout << floor[i] << endl;
	}


	return 0;
}

