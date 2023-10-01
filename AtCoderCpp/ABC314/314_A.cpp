#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main_314A() {

	int n;

	string s = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

	cin >> n;

	string ans = s.substr(0, n+2);
	cout << ans << endl;


	


	return 0;
}