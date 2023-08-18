#include <iostream>
#include <vector>

using namespace std;

int main_312A() {

	string s;
	cin >> s;
	string ans;

	if (s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA" || s == "EGB" || s == "FAC" || s == "GBD" ) {
		ans = "Yes";
	}
	else {
		ans = "No";
	}

	cout << ans << endl;

	return 0;
}