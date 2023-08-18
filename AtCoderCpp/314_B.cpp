#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<vector<int>> a(n);
	vector<int> c;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		c.push_back(tmp);


		for (int j = 0; j < tmp; j++) {
			int val;
			cin >> val;
			a.at(i).push_back(val);
		}
	}

	int x;
	cin >> x;

	vector<int> anss;
	int min = 100;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a.at(i).size(); j++) {
			if (x == a.at(i).at(j)) {
				anss.push_back(i);
				min = std::min(min, c.at(i));
			}
		}
	}

	vector<int> ans;

	for (int i = 0; i < anss.size(); i++) {
		if (c.at(anss.at(i)) == min) {
			ans.push_back(anss.at(i));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;;
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) {
			cout << ans.at(i)+1 << endl;
		}
		else {
			cout << ans.at(i)+1 << " ";
		}
		
	}





	return 0;
}