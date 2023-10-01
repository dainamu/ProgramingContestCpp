#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main_311C() {

	int n, m;
	cin >> n >> m;

	vector<vector<char>> s(n);

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < m; j++) {
			s.at(i).push_back(str.at(j));
		}


	}
	cout << "-------------------------------------------" << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		
		string str(s.at(i).begin(), s.at(i).end());
		cout << str << endl;
	}

	
	return 0;
}