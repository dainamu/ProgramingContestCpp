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
 * aribon P37 幅優先探索 org
 *
*/
/*
コメントアウト Ctrl + K → C
コメント外す   Ctrl + K → U
*/
int main() {
	IOS;
	fin_open();
	int n, m;
	ifs >> n >> m;

	vector<string> maze(n);

	// start , goalの場所記録用
	int sx = 0;
	int sy = 0;
	int gx = 0;
	int gy = 0;
	for (int i = 0; i < n; i++) {
		ifs >> maze[i];
		for (int j = 0; j < maze[i].size(); j++) {
			if (maze[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (maze[i][j] == 'G') {
				gx = i;
				gy = j;
			}
		}
	}

	// キューを準備
	queue<pair<int, int>> q;
	// スタート位置をプッシュ
	q.push({ sx, sy });

	// 答えようの配列
	vector<vector<int>> ans(n, vector<int>(m, -1));

	// スタートを0で初期化
	ans[sx][sy] = 0;
	// 4方向用の配列
	int di[] = { -1, 0, 1, 0 };
	int dj[] = { 0,1,0,-1 };

	// キューが空でない間繰り返す
	while (!q.empty()) {
		pair<int, int> p;
		p = q.front(); // キューの先頭要素を取得
		q.pop(); // キューの先頭要素をポップする

		for (int i = 0; i < 4; i++) {
			// ↑→↓←の添え字
			int nx = p.first + di[i];
			int ny = p.second + dj[i];

			// 範囲外でないかつ、壁でない場合
			if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#') {
				// まだ到達してない場合
				if (ans[nx][ny] == -1) {
					// 今のポジションから+１で到達できる
					ans[nx][ny] = ans[p.first][p.second] + 1;
					// 新しいポジションをプッシュ
					q.push({ nx, ny });
				}
			}


		}


	};
	// 答えようの配列を出力
	for (vector<int> a : ans) {
		for (int x : a) {
			string s = "";
			s += "  " + to_string(x);// 先頭に空白2つ
			//cout << s;
			s = s.substr(s.size() - 3);//後ろから3文字分
			cout << s << ",";
		}
		cout << endl;
	}
	cout << ans[gx][gy] << endl;

}