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
 * aribon P37 ���D��T�� org
 *
*/
/*
�R�����g�A�E�g Ctrl + K �� C
�R�����g�O��   Ctrl + K �� U
*/
int main() {
	IOS;
	fin_open();
	int n, m;
	ifs >> n >> m;

	vector<string> maze(n);

	// start , goal�̏ꏊ�L�^�p
	int sx = 0;
	int sy = 0;
	int gx = 0;
	int gy = 0;
	for (int i = 0; i < n; i++) {
		ifs >> maze[i];
		for (int j = 0; j < maze[i].size(); j++) {
			if (maze[i][j] == 'S') {
				sx = i;
				sy = j;
			}
			else if (maze[i][j] == 'G') {
				gx = i;
				gy = j;
			}
		}
	}

	// �L���[������
	queue<pair<int, int>> q;
	// �X�^�[�g�ʒu���v�b�V��
	q.push({ sx, sy });

	// �����悤�̔z��
	vector<vector<int>> ans(n, vector<int>(m, -1));

	// �X�^�[�g��0�ŏ�����
	ans[sx][sy] = 0;
	// 4�����p�̔z��
	int di[] = { -1, 0, 1, 0 };
	int dj[] = { 0,1,0,-1 };

	// �L���[����łȂ��ԌJ��Ԃ�
	while (!q.empty()) {
		pair<int, int> p;
		p = q.front(); // �L���[�̐擪�v�f���擾
		q.pop(); // �L���[�̐擪�v�f���|�b�v����

		for (int i = 0; i < 4; i++) {
			// ���������̓Y����
			int nx = p.first + di[i];
			int ny = p.second + dj[i];

			// �͈͊O�łȂ����A�ǂłȂ��ꍇ
			if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#') {
				// �܂����B���ĂȂ��ꍇ
				if (ans[nx][ny] == -1) {
					// ���̃|�W�V��������+�P�œ��B�ł���
					ans[nx][ny] = ans[p.first][p.second] + 1;
					// �V�����|�W�V�������v�b�V��
					q.push({ nx, ny });
				}
			}


		}


	};
	// �����悤�̔z����o��
	for (vector<int> a : ans) {
		for (int x : a) {
			string s = "";
			s += "  " + to_string(x);// �擪�ɋ�2��
			//cout << s;
			s = s.substr(s.size() - 3);//��납��3������
			cout << s << ",";
		}
		cout << endl;
	}
	cout << ans[gx][gy] << endl;

}