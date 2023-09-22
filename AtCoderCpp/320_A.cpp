#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_320A() {

	int a, b;
	cin >> a >> b;

	long total = pow(a, b) + std::pow(b, a);
	cout << total << endl;


	return 0;
}