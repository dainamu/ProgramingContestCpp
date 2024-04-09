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
 * aribon P37 ���D��T�� �����
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
	int sx, sy;//�X�^�[�g�n�_
	int gx, gy;// �S�[���n�_
	// ��Ԃ�\���N���XPair�̏ꍇ�Atypedef���Ă����ƕ֗�
	typedef pair<int, int> P;

	// ����
	ifs >> n >> m;
	vector<string> maze(n); // ���H�p
	for (int i = 0; i < n; i++) {
		ifs >> maze[i];
		for (int j = 0; j < maze[i].size(); j++) {
			if (maze[i][j] == 'S') {
				sx = i; sy = j;
			}
			else if (maze[i][j] == 'G') {
				gx = i; gy = j;
			}
		}
	}

	vector<vector<int>> d(n, vector<int>(m, INF)); // �e�_�܂ł̍ŒZ�����̔z���INF�ŏ�����

	// �ړ�4�����̃x�N�g��
	int dx[4] = { 1,0,-1,0 }; int dy[4] = { 0,1,0,-1 };

	auto bfs = [&]() {
		queue<P> que;
		// �X�^�[�g�n�_��0�ɂ��āA�L���[�ɓ����
		que.push(P(sx, sy));
		d[sx][sy] = 0;

		// �L���[����ɂȂ�܂Ń��[�v
		while (que.size()) {
			// �L���[�̐擪�����o��
			P p = que.front();
			que.pop();

			// ���o���Ă�����Ԃ��S�[���Ȃ�T������߂�
			if (p.first == gx && p.second == gy)break;

			// 4���������[�v����
			for (int i = 0; i < 4; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				// �ړ��\���A�����B������
				if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INF) {

					// �ړ��\�ł���΃L���[�ɂ���āA���̓_�̋�����p����̋���+1�Ŋm�肷��
					d[nx][ny] = d[p.first][p.second] + 1;
					que.push(P(nx, ny));
				}
			}


		}
		return d[gx][gy];
		};

	int res = bfs();
	cout << res << endl;

}