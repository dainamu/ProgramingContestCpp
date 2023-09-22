#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_317B() {

	int n;
	cin >> n;
	vector<int> A(n);
	int min = 1001;
	req(i, n) {
		cin >> A.at(i);

		min = std::min(min, A.at(i));

	}

	int total = 0;
	int total_A = 0;
	for (int i = 0; i < n+1; i++) {

		total += min + i;
		total_A += A.at(i);
	}

	cout << total - total_A << endl;

	return 0;


}