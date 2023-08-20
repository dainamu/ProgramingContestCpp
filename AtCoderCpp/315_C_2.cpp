#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)
using namespace std;


// pariÇÃî‰ärä÷êî
bool compare_by_b(pair<int, int> a, pair<int, int> b) {

	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}


int main() {

	int N;
	cin >> N;

	vector<pair<long, int>> ice(N);

	req(i, N) {
		cin >> ice.at(i).second;
		cin >> ice.at(i).first;
	}
	
	// Ç®Ç¢ÇµÇ≥ÇÃè∏èá
	sort(ice.begin(), ice.end());

	pair<long, int> a1;
	a1 = ice.at(N - 1);

	long manzoku = 0;
	for (int i = 0; i < N-1; i++) {

		if (a1.second == ice.at(i).second) {
			// ìØÇ∂ñ°
			manzoku = max((a1.first + ice.at(i).first / 2), manzoku);
		}
		else {
			// à·Ç§ñ°
			manzoku = max((a1.first + ice.at(i).first), manzoku);
		}

	}

	cout << manzoku << endl;

	return 0;
}