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

int dx[] = { -1,0,1, 0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dy[] = { 0 ,1,0,-1, 1,1,-1,-1,0 };

//int dx[] = { 1,0, -1, 0,-1,1,1,-1,0 }; // ↓ → ↑ ←
//int dy[] = { 0,1, 0 ,-1, 1,1,-1,-1,0 };

/*
概要：
　右に行けるところまで行ったら次は下、左、上、右・・・を繰り返す。（渦巻状のイメージ）
  その際gird上のマス目を手数を記録していき最後に出力
  真ん中は'T'を出力する
  BFSっぽい感じで実装

*/
signed main() {
	IOS;

	int n;
	cin >> n;

	// 答え用の2次元配列を0で初期化
	vector<vector<int>> grid(n, vector<int>(n, 0));

	// 中央は-1にしておく
	grid[n / 2][n / 2] = -1;

	// キュー準備
	queue<pair<int, int>> q;
	q.push({ 0,0 });//スタート地点を追加
	grid[0][0] = 1; // スタート地点を1にする

	int dir = 1; // 方向用の変数
	while (!q.empty()) {
		// キューの先頭要素からx,yを取得
		int x = q.front().first;
		int y = q.front().second;

		// 次のマス目の座標を計算
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {

			dir = (dir + 1) % 4;//90度方向転換する
			continue;
		}
		if (grid[nx][ny] > 0) {
			// すでに訪問済みの場合
			dir = (dir + 1) % 4;//90度方向転換する
			continue;
		}

		if (grid[nx][ny] == -1) {
			// 中央の場合
			q.pop(); //終わりなので先頭要素を削除
			continue;
		}

		grid[nx][ny] = grid[x][y] + 1; // 次のマス目を+1で確定させる
		q.pop(); // 先頭要素を削除
		q.push({ nx, ny }); // 次のマス座標を追加


	}
	// グリッドを出力
	rep(i, n) {
		rep(j, n) {
			if (grid[i][j] == -1) {
				cout << 'T' << ' ';
				continue;
			}
			cout << grid[i][j] << ' ';

		}
		cout << endl;
	}

}


