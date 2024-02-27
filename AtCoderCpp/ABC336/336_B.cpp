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

//int dx[] = { -1,0,1, 0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
//int dy[] = { 0 ,1,0,-1, 1,1,-1,-1,0 };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

/*
 * @file abc336b
 *
*/

signed main() {
	IOS;

	int n;
	cin >> n;
	bitset<50> bs = bitset<50>(n); // 50ビットのビット集合を河内区
	string bs_str = bs.to_string(); // 文字列変換
	int cnt = 0;
	for (int i = 49; i >= 0; i--) {

		if (bs_str[i] != '0') {
			break;
		}
		cnt++;
	}
	cout << cnt << endl;
	return 0;

}