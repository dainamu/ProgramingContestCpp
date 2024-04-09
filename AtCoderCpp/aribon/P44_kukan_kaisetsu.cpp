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
 *
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
	int n;
	ifs >> n;
	vector<pair<int, int>> p(n); //pair�^��vector
	for (int i = 0; i < n; i++) {
		ifs >> p[i].first; // �J�n����
	}
	for (int i = 0; i < n; i++) {
		ifs >> p[i].second; // �I������
	}

	rep(i, n) {
		cout << p[i].second << endl;
	}
	// �I�����Ԃ̏��������Ƀ\�[�g
	// pair�^�̔z��̃\�[�g second�̏����Ƀ\�[�g
	sort(p.begin(), p.end(), [&](pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		else {
			return a.first < b.first;
		}
		});

	cout << "�\�[�g��" << endl;
	rep(i, n) {
		cout << p[i].second << endl;
	}
	cout << "��" << endl;
	int ans = 0, t = 0; // t�͍Ō�ɑI�񂾎d���̏I������
	for (int i = 0; i < n; i++) {
		if (t < p[i].first) {
			ans++;
			t = p[i].second;
		}
	}
	cout << ans << endl;


}