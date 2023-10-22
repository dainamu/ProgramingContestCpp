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
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
	if (left.first == right.first) {
		return left.second < right.second;
	}
	else {
		return right.first < left.first;
	}
}
signed main() {

	
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) {
		cin >> s[i];
	}

	vector<int> kachi(n);
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i][j] == 'o') {
				kachi[i]++;
			}
		}
		p.push_back({kachi[i], i});
	}

	sort(p.begin(), p.end(), desc_asc);
	// test

	rep(i, n) {
		//cout << " 勝ち数：" << p[i].first << "プレイヤー番号："  << p[i].second << endl;
		//cout << "プレイヤー番号：" << p[i].second << " 勝ち数：" << p[i].first << endl;

	}
	// kokomade

	for (int i = 0; i < n; i++) {
		cout << p[i].second + 1 << " ";
	}
	return 0;
	
}

