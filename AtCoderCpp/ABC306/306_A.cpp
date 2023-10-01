#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

signed main() {

	int n;
	string s;
	cin >> n;
	cin >> s;
	string ans;
	rep(i, s.length()) {

		ans.push_back(s[i]);
		ans.push_back(s[i]);

	}
	cout << ans << endl;
	return 0;

}