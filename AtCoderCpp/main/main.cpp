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
 * P47 その他の問題
 * 
*/
/*
コメントアウト Ctrl + K → C
コメント外す   Ctrl + K → U
*/
int main() {
	IOS;
	
	fin_open();

	// 入力
	int n, r;
	ifs >> n >> r;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		ifs >> x[i];
	}

	int cnt = 0; // 答え用
	int len = 0; // x+r
	vector<bool> chk(n); // 印付けたかつけないか

	for (int i = 0; i < n; i++) {

		len = x[i] + r; // R以内の距離
		int temp = i;
		for (int j = i; j < n; j++) {
			if (x[j] <= len) { //R以内の距離の場合
				temp = j;
			}
			else {
				break;
			}
		}

		// もしtempがiのままならiに印をつける
		if (temp == i) {
			chk[i] = true;
		}
		else {
			// そうでなければtempにチェックをいれる
			chk[temp] = true;
			// r範囲まですすめる
			len = x[temp] + r;
			for (int j = temp; j < n; j++) {
				if (x[j] <= len) {
					temp = j;
				}
				else {
					break;
				}
			}
		}
		// iをtempで更新する
		i = temp;

	}

	cnt = count(chk.begin(), chk.end(), true);
	cout << cnt << endl;

}