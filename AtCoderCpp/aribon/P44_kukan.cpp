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
 *  aribon  P44 貪欲法 区間問題 org
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
	int n;
	ifs >> n;
	vector<int> s(n); // 開始時間
	vector<int> t(n); // 終了時間
	for (int i = 0; i < n; i++) {
		ifs >> s[i];
	}
	for (int i = 0; i < n; i++) {
		ifs >> t[i];
	}

	int now = 0; // 現在時刻

	int cnt = 0; // 回答用

	for (int ni = 0; ni < n; ni++) {

		vector<int> temp;
		for (int i = 0; i < n; i++) {
			if (now < s[i]) {
				temp.push_back(i);
			}
		}
		int mn = INF;
		for (int i = 0; i < temp.size(); i++) {
			mn = min(mn, t[temp[i]]);
		}

		auto itr = find(t.begin(), t.end(), mn);
		if (itr != t.end()) {
			cnt++;
			now = mn;
		}
		else {
			break;
		}
	}
	cout << cnt << endl;
}