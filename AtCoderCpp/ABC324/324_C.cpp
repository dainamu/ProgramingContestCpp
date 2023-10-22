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
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()


using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

ll n;
string s[500001], t2;
ll a[500001], b[500001];

ll calc(const string& s, const string& t) {
	for (int i = 0; i < (int)t.size(); i++) {
		if (i >= s.size())return s.size();
		if (s[i] != t[i]) {
			return i;
		}
	}
	return t.size();
}

signed main() {

	cin >> n >> t2;
	for (int i = 1; i <= n; i++)cin >> s[i];
	for (int i = 1; i <= n; i++)a[i] = calc(s[i], t2);
	reverse(t2.begin(), t2.end());
	for (int i = 1; i <= n; i++) {
		reverse(s[i].begin(), s[i].end());
		b[i] = calc(s[i], t2);
	}
	vector<ll> ans;
	for (int i = 1; i <= n; i++) {
		const string& t = s[i];
		bool flag = false;
		if (a[i] == t.size() && t.size() == t2.size()) flag = true;
		if (a[i] + b[i] >= t.size() && t.size() + 1 == t2.size())flag = true; // �S��v��T�̒�����1����
		if (a[i] + b[i] >= t.size() - 1 && t.size() - 1 == t2.size())flag = true; // �ꕶ���ȊO��v�ŁAt��1��������
		if (a[i] + b[i] == t.size() - 1 && t.size() == t2.size())flag = true; // �ꕶ���Ⴂ�Œ����ꏏ�i�v�͈ꕶ�����ꂩ����Γ��������ɂȂ�j
		if (flag) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << " ";
	cout << endl;

	return 0;

}

