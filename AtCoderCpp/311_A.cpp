#include <iostream>
#include <vector>

using namespace std;

int main_311A() {

	int n;
	string s;

	cin >> n;
	cin >> s;
	bool a = false;
	bool b = false;
	bool c = false;

	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		
		if (s.at(i) == 'A') a = true;
		if (s.at(i) == 'B') b = true;
		if (s.at(i) == 'C') c = true;

		if (a && b && c) {
			ans = i;
			break;
		}
	}

	ans++;
	cout << ans << endl;



	return 0;
}