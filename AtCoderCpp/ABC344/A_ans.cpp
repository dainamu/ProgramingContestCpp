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
 * ABC344 A�̉���R�[�h
 *
*/

int main() {
	IOS;
	string s;
	string ans;
	cin >> s;
	int cnt = 0;
	// �_�̏o���������𐔂��Ă�����1�{�̏ꍇ�o�͂��Ȃ�
	for (char c : s) {
		if (c == '|') {
			cnt++;
		}
		else {
			if (cnt != 1) {
				ans += c;
			}
		}
	}

	cout << ans << endl;
}