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
#include <stack>
#include <regex>
#include<stacktrace>
#include <fstream>
//#include <print>
//#include <format>

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


ifstream ifs;
/*
*ファイルから入力受け取る場合cinのかわりにifsをつかう
* 
* ifs >> str;
* 
*/
int fin_open() {

	string fileName;
	cin >> fileName;
	fileName = fileName + ".txt";

	ifs.open(fileName, ios::in);
	
	if (!ifs) {
		cerr << "ファイルを読込めませんでした。" << endl;
		return 1;
	}
	return 0;
}
/*
 * @file 
 * ABC 348 D
 * 
 * 
 * 
*/
/*
コメントアウト Ctrl + K → C
コメント外す   Ctrl + K → U
*/

int main() {
	IOS;

	//fin_open();
	
	// 入力
	int h, w, n;
	cin >> h >> w;

	vector<string> grid(h); // グリッド図
	vector<vector<int>> energy(h, vector<int>(w)); // エネルギーの位置と量を記録するよう

	// スタート地点、ゴール地点
	int sx, sy, gx, gy;

	// グリッド
	for (int i = 0; i < h; i++) {
		cin >> grid[i];
		if (grid[i].find("S") != string::npos) {
			sx = i;
			sy = grid[i].find("S");
		}
		if (grid[i].find("T") != string::npos) {
			gx = i;
			gy = grid[i].find("T");
		}

	}
	cin >> n;
	// エネルギーの位置と量
	for (int i = 0; i < n; i++) {
		int r, c, e;
		cin >> r >> c >> e;
		r--;
		c--;
		energy[r][c] = e;
	}

	// 行ったか、行ってないか
	vector<vector<bool>> visited(h, vector<bool>(w));

	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0,1,0,-1 };
	auto dfs = [&](auto dfs, int x, int y, int en, vector<vector<bool>> visited)->bool	{
		
		// ゴールならtrueリターン
		if (x == gx && y == gy) {
			return true;
		}

		// 訪問ずみならリターン
		if (visited[x][y]) {
			return false;
		}
		else {
			// 訪問済みにsるう
			visited[x][y] = true;
		}
		// もしエネルギー0で現在値にエネルギーがなかったらfalse
		if (en == 0 && energy[x][y] == 0) {
			return false;
		}

		if (en < energy[x][y]) {
			// 現在のエネルギーより落ちてるエネルギーの方が大きければ使う。
			en = energy[x][y];
		}
		// 4方向
		for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] != '#') {
					if (dfs(dfs, nx, ny, en,visited)) {
						return true;
					}
				}
		}

		// 最後まできてダメだったらリターンfalse
		return false;


		};

	bool ans = dfs(dfs, sx, sy, 0, visited);
	if (ans)cout << "Yes" << endl;
	else cout << "No" << endl;
} 