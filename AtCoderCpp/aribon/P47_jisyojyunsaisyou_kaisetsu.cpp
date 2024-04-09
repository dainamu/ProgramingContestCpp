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
 * P47 辞書順最小の問題 解説
 *
*/
/*
コメントアウト Ctrl + K → C
コメント外す   Ctrl + K → U
*/
int main() {
	IOS;

	fin_open();

	int n;
	string s;
	ifs >> n >> s;

	int a = 0, b = n - 1; // 残っている文字

	string t;
	while (a <= b) {
		bool left = true;

		for (int i = 0; i + a <= b; i++) {
			if (s[a + i] < s[b - i]) {
				left = true;
				break;
			}
			else if (s[a + i] > s[b - i]) {
				left = false;
				break;

			}

		}

		if (left) {
			t.push_back(s[a]);
			a++;
		}
		else {
			t.push_back(s[b]);
			b--;

		}
	}

	cout << t << endl;


}