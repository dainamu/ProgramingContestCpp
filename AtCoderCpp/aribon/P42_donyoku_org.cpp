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
*�t�@�C��������͎󂯎��ꍇcin�̂�����ifs������
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
		cerr << "�t�@�C����Ǎ��߂܂���ł����B" << endl;
		return;
	}
}
/*
 * @file
 * aribon  P42 �×~�@ �d�ݖ�� org
 *
*/
/*
�R�����g�A�E�g Ctrl + K �� C
�R�����g�O��   Ctrl + K �� U
*/
int main() {
	IOS;

	fin_open();

	// ����
	int coin[6];
	int A;
	for (int i = 0; i < 6; i++) {
		ifs >> coin[i];
	}
	ifs >> A;

	int res = 0;
	int now = 0;


	while (A != 0) {
		if (A >= 500 && coin[5] >= 1) {
			coin[5]--;
			A -= 500;
			res++;
			continue;
		}
		if (A >= 100 && coin[4] >= 1) {
			coin[4]--;
			A -= 100;
			res++;
			continue;
		}
		if (A >= 50 && coin[3] >= 1) {
			coin[3]--;
			A -= 50;
			res++;
			continue;
		}
		if (A >= 10 && coin[2] >= 1) {
			coin[2]--;
			A -= 10;
			res++;
			continue;
		}
		if (A >= 5 && coin[1] >= 1) {
			coin[1]--;
			A -= 5;
			res++;
			continue;
		}
		if (A >= 1 && coin[0] >= 1) {
			coin[0]--;
			res++;
			A -= 1;
			continue;
		}
	}

	cout << res;
}