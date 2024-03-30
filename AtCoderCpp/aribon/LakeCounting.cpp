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
#include <queue>
#include <numeric>
//#include <format>
#include <stack>
#include <regex>
//#include <print>
#include<stacktrace>
#include <fstream>

#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const char nl = '\n';
const int INF = 102345678;
using namespace std;
using P = pair<int, int>;
using ll = long long;
using ull = unsigned long long;


/*
 * @file
 *
*/
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

ifstream ifs;

void fin_open() {

	string fileName;
	cin >> fileName;
	fileName = fileName + ".txt";

	ifs.open(fileName, ios::in);

	if (!ifs) {
		cerr << "ファイルを読込めませんでした。" << endl;
		return;
	}
}

int main() {
	IOS;

	fin_open();

	int n, m;
	ifs >> n >> m;

	vector<string> mp(n);

	for (int i = 0; i < n; i++) {
		ifs >> mp[i];
	}

	auto f = [&](auto f, int wi, int wj) {

		// もし現在のマスが水たまりの場合 "."に変換する
		if (mp[wi][wj] == 'w') {
			mp[wi][wj] = '.';
		}
		else {
			// そうでなければなにもしない
			return;
		}
		for (int di = 0; di < 8; di++) {
			// 範囲外はリターン
			if (wi + dx[di] < 0 || wi + dx[di] >= n || wj + dy[di] < 0 || wj + dy[di] >= m) return;
			// 八方向にdfsを呼び出す
			f(f, wi + dx[di], wj + dy[di]);

		}

		};

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 'w') { f(f, i, j); cnt++; }
		}
	}
	cout << cnt << endl;
}