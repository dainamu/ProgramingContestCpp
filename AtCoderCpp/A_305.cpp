#include <iostream>
#include <vector>

using namespace std;

int main_305() {

	int N;
	cin >> N;
	int ans;
	int mod = N % 5;
	if (mod == 0) {
		ans = N;
	}
	else if (mod < 3) {
		ans = N - mod;
	}
	else {
		ans = N + (5-mod);
	}
	cout << ans << endl;
	return 0;
}