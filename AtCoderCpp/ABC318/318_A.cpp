#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

int main() {

	int n, m, p;
	cin >> n >> m >> p;

	int ans = 1;

	int tmp = n - m;
	if (tmp < 0) {
		cout << 0 << endl;
		return 0;
	}
	ans += tmp / p;
	cout << ans << endl;

	return 0;
}