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


signed main() {
	IOS;

	int n, q;
	cin >> n >> q;
	// パーツの座標用の配列を用意
	deque<pair<int, int>> parts;
	// パーツ座標初期化x=i,y=0
	for (int i = 1; i <= n; i++) {
		parts.emplace_back(i, 0);
	}

	// q個クエリを処理
	while (q--) {
		int num;
		cin >> num;

		if (num == 1) {
			char c;
			cin >> c;
			auto [x, y] = parts.front();// 先頭要素取得
			// 新しい先頭座標を先頭に追加
			if (c == 'U')parts.push_front({ x, y + 1 });
			if (c == 'R')parts.push_front({ x + 1, y });
			if (c == 'D')parts.push_front({ x, y - 1 });
			if (c == 'L')parts.push_front({ x - 1, y });
			// 末尾要素を削除
			parts.pop_back();

		}
		else if (num == 2) {
			int p;
			cin >> p;
			p--;
			// p番のパーツの座標を出力
			cout << parts[p].first << ' ' << parts[p].second << nl;
		}


	}

	return 0;

}