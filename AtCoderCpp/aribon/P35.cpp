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
		cerr << "�t�@�C����Ǎ��߂܂���ł����B" << endl;
		return;
	}
}


int n, k;
vector<int> x;

bool dfs(int i, int sum) {
	// i ��n�܂ł��߂����Ƃ� sum��k�ƈ�v���Ă��邩�Ԃ�
	if (i == n)return sum == k;

	// i�Ԗڂ��g��Ȃ��p�^�[��
	if (dfs(i + 1, sum))return true;
	// i�Ԗڂ��g���p�^�[��
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

	// dfs����ԍŏ��̏�ԂŌĂяo���B
	if (dfs(0, 0)) cout << "Yes" << endl;
	else cout << "No" << endl;



	return 0;
}