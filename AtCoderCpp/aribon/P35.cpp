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
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

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


int n, k;
vector<int> x;

bool dfs(int i, int sum) {
	// i をnまでためしたとき sumがkと一致しているか返す
	if (i == n)return sum == k;

	// i番目を使わないパターン
	if (dfs(i + 1, sum))return true;
	// i番目を使うパターン
	if (dfs(i + 1, sum + x[i])) return true;

	return false;
}
int main() {
	IOS;

	fin_open();


	ifs >> n;
	x = vector<int>(n);
	for (int i = 0; i < n; i++) {
		ifs >> x[i];
	}
	ifs >> k;

	// dfsを一番最初の状態で呼び出す。
	if (dfs(0, 0)) cout << "Yes" << endl;
	else cout << "No" << endl;



	return 0;
}