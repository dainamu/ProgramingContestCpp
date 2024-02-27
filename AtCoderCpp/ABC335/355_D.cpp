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

int dx[] = { -1,0,1, 0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dy[] = { 0 ,1,0,-1, 1,1,-1,-1,0 };

//int dx[] = { 1,0, -1, 0,-1,1,1,-1,0 }; // �� �� �� ��
//int dy[] = { 0,1, 0 ,-1, 1,1,-1,-1,0 };

/*
�T�v�F
�@�E�ɍs����Ƃ���܂ōs�����玟�͉��A���A��A�E�E�E�E���J��Ԃ��B�i�Q����̃C���[�W�j
  ���̍�gird��̃}�X�ڂ��萔���L�^���Ă����Ō�ɏo��
  �^�񒆂�'T'���o�͂���
  BFS���ۂ������Ŏ���

*/
signed main() {
	IOS;

	int n;
	cin >> n;

	// �����p��2�����z���0�ŏ�����
	vector<vector<int>> grid(n, vector<int>(n, 0));

	// ������-1�ɂ��Ă���
	grid[n / 2][n / 2] = -1;

	// �L���[����
	queue<pair<int, int>> q;
	q.push({ 0,0 });//�X�^�[�g�n�_��ǉ�
	grid[0][0] = 1; // �X�^�[�g�n�_��1�ɂ���

	int dir = 1; // �����p�̕ϐ�
	while (!q.empty()) {
		// �L���[�̐擪�v�f����x,y���擾
		int x = q.front().first;
		int y = q.front().second;

		// ���̃}�X�ڂ̍��W���v�Z
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {

			dir = (dir + 1) % 4;//90�x�����]������
			continue;
		}
		if (grid[nx][ny] > 0) {
			// ���łɖK��ς݂̏ꍇ
			dir = (dir + 1) % 4;//90�x�����]������
			continue;
		}

		if (grid[nx][ny] == -1) {
			// �����̏ꍇ
			q.pop(); //�I���Ȃ̂Ő擪�v�f���폜
			continue;
		}

		grid[nx][ny] = grid[x][y] + 1; // ���̃}�X�ڂ�+1�Ŋm�肳����
		q.pop(); // �擪�v�f���폜
		q.push({ nx, ny }); // ���̃}�X���W��ǉ�


	}
	// �O���b�h���o��
	rep(i, n) {
		rep(j, n) {
			if (grid[i][j] == -1) {
				cout << 'T' << ' ';
				continue;
			}
			cout << grid[i][j] << ' ';

		}
		cout << endl;
	}

}


