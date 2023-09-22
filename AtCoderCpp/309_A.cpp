#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_309A() {

	int a, b;
	cin >> a >> b;
	int t = b - a;
	if (t == 1 && (b != 1 && b != 4 && b != 7)) {
		cout << "Yes" << endl;
	}
	else {

		cout << "No" << endl;
	}
	
	return 0;
}