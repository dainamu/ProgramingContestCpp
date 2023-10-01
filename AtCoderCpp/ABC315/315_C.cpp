#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_315C_1() {

	int N;
	cin >> N;

	vector<pair<int, long>> ice(N);

	req(i, N) {
		cin >> ice.at(i).first;
		cin >> ice.at(i).second;
	}

	long manzoku = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			
			if (ice.at(i).first != ice.at(j).first) {
				// –¡‚ªˆÙ‚È‚é

				// –ž‘«“x
				manzoku = max((ice.at(i).second + ice.at(j).second), manzoku);

			}
			else {
				// –¡‚ª“¯‚¶

				// –¡‚ª’á‚¢‚Ù‚¤‚ð”¼•ª
				long tmp;
				tmp = min(ice.at(i).second, ice.at(j).second);
				manzoku = max((ice.at(i).second + ice.at(j).second - tmp / 2), manzoku);
			}

			
		}
	}

	cout << manzoku << endl;

	return 0;
}