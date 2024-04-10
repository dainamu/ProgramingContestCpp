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
 * ABC 348 B
 * 
 * ポイント： 小数の比較はかならず誤差がでるので整数のまま比較する
 * 
*/
/*
コメントアウト Ctrl + K → C
コメント外す   Ctrl + K → U
*/
int pow2(int d) { return d * d; }
int main() {
	IOS;

	//fin_open();
	
	// 入力
	int n;
	cin >> n;
	
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	// 答えようの配列
	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		int d_max = -1;
		for (int j = 0; j < n; j++) {
			int dist = pow2(x[i] - x[j]) + pow2(y[i] - y[j]); // ルートをとると小数になり誤差がでるので整数のまま比較
			if (dist > d_max) {
				d_max = dist; // よりおおきくなったら答えを更新
				ans[i] = j;
			}
		}
	}
	for (int val : ans) {
		cout << val+1 << endl;
	}

}