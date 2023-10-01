#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_315B() {

	int m;
	cin >> m;
	vector<int> d(m);
	int total = 0;

	req(i, m) {

		cin >> d.at(i);
		total += d.at(i);
	}

	vector<int> month(m);
	vector<int> dates(total);

	int harf = (total + 1) / 2;

	int cnt = 1;
	
	int ansM = 0;
	int ansD = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < d.at(i); j++) {
			if (cnt == harf) {
				ansM = i;
				ansD = j;
				goto exit;
			}
			cnt++;
		}
	}
	exit:
	ansM++;
	ansD++;
	cout << ansM << " " << ansD << endl;





	return 0;
}