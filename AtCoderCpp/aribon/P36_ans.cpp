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


int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };

ifstream ifs;
/*
*ファイルから入力受け取る場合cinのかわりにifsをつかう
*
* ifs >> str;
*
*/
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
/*
 * @file
 * aribon P36 の見本
 *
*/
void dfs(vector<string>& vec, int x, int y) {
	// いまいるところを.にする
	vec[x][y] = '.';

	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int nx = x + dx;
			int ny = y + dy;

			// サイズの確認と次の場所がｗの場合
			if (0 <= nx && nx < vec.size() && 0 <= ny && ny < vec[x].size() && vec[nx][ny] == 'w') {
				dfs(vec, nx, ny);
			}
		}
	}

	return;

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
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mp[i][j] == 'w') {
				dfs(mp, i, j);
				cnt++;
			}
		}
	}
	cout << cnt;

}