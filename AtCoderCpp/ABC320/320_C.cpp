#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;

int main_320C() {

	int m;
	vector<string> s(3);
	cin >> m;
	rep(i, 3) cin >> s.at(i);
	const int INF = 1001001001;
	int ans = INF;
	rep(t0, 300)rep(t1, 300)rep(t2, 300) {

		if (t0 == t1) continue;
		if (t0 == t2) continue;
		if (t1 == t2) continue;
		if (s[0][t0 % m] != s[1][t1 % m]) continue;
		if (s[0][t0 % m] != s[2][t2 % m]) continue;
		ans = min(ans, max({ t0, t1, t2 }));

	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	
	return 0;
}