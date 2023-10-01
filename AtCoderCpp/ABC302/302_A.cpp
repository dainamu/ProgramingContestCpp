#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;

int main_302A() {

	ll a, b;
	cin >> a >> b;

	ll ans = 0;
	ll mod = a / b;
	if (a % b) {
		mod++;
	}
	cout << mod << endl;

	return 0;
}

