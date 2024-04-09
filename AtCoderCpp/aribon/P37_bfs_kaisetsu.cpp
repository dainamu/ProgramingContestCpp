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
 * aribon P37 幅優先探索 解説版
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
	int sx, sy;//スタート地点
	int gx, gy;// ゴール地点
	// 状態を表すクラスPairの場合、typedefしておくと便利
	typedef pair<int, int> P;

	// 入力
	ifs >> n >> m;
	vector<string> maze(n); // 迷路用
	for (int i = 0; i < n; i++) {
		ifs >> maze[i];
		for (int j = 0; j < maze[i].size(); j++) {
			if (maze[i][j] == 'S') {
				sx = i; sy = j;
			}
			else if (maze[i][j] == 'G') {
				gx = i; gy = j;
			}
		}
	}

	vector<vector<int>> d(n, vector<int>(m, INF)); // 各点までの最短距離の配列をINFで初期化

	// 移動4方向のベクトル
	int dx[4] = { 1,0,-1,0 }; int dy[4] = { 0,1,0,-1 };

	auto bfs = [&]() {
		queue<P> que;
		// スタート地点を0にして、キューに入れる
		que.push(P(sx, sy));
		d[sx][sy] = 0;

		// キューが空になるまでループ
		while (que.size()) {
			// キューの先頭を取り出す
			P p = que.front();
			que.pop();

			// 取り出してきた状態がゴールなら探索をやめる
			if (p.first == gx && p.second == gy)break;

			// 4方向をループする
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				// 移動可能かつ、未到達か判定
				if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF) {

					// 移動可能であればキューにいれて、その点の距離をpからの距離+1で確定する
					d[nx][ny] = d[p.first][p.second] + 1;
					que.push(P(nx, ny));
				}
			}


		}
		return d[gx][gy];
		};

	int res = bfs();
	cout << res << endl;

}