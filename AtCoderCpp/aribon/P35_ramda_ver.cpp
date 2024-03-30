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

int main() {
	IOS;

	fin_open();

	int n, k;
	ifs >> n;
	vector<int> x(n);

	for (int i = 0; i < n; i++) {
		ifs >> x[i];
	}

	ifs >> k;

	auto f = [&](auto f, int i, int sum) {
		if (i == n)return k == sum;

		if (f(f, i + 1, sum))return true;
		if (f(f, i + 1, sum + x[i]))return true;
		return false;
		};

	if (f(f, 0, 0))cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}