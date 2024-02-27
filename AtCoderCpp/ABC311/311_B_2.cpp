#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#include <compare>
#include <bitset>
//#include <format>
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()

using namespace std;
using P = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

using P = pair<int, int>;


signed main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (auto& e : s)cin >> e;

	vector<int> si(n);
	for (int i = 0; i < n; i++) {
		string tmp = s[i];
		replace(tmp.begin(), tmp.end(), 'o', '1');
		replace(tmp.begin(), tmp.end(), 'x', '0');

		si[i] = std::stoi(tmp, 0, 2);
		//cout << format("{:0>5b}", si[i]) << endl;
	}

	int lp = si[0];
	for (int i = 1; i < n; i++) {
		lp = lp & si[i];

	}

	//cout << format("{:0>5b}", lp) << endl;
	string strLp = bitset<25 * sizeof(int)>(lp).to_string();
	//cout << strLp << endl;

	vector<int> ans(m);
	bool ok = false;
	int cnt = 0;
	int st = 0;

	while (strLp.size() > 0) {

		if (strLp.back() == '1') {
			cnt++;
			ok = true;
		}
		else {
			st++;
			ok = false;
			cnt = 0;
		}

		if (ok) {
			ans[st] = cnt;
		}
		strLp.pop_back();

	}
	int val = *max_element(ALL(ans));
	cout << val << endl;
	return 0;


}

