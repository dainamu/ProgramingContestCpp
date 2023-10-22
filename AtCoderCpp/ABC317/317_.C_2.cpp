#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <string>
#include <cmath>
#include <set>
#include <unordered_set>
#define rep(i, n) for(int i=0; i<(n); i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

struct Edge {

	// �����o�ϐ�
	int to;
	int cost;

	// �R���X�g���N�^ �f�t�H���g�������Ƃ�
	// : �R�����ȍ~�̓����o�������q���X�g
	Edge(int t = 0, int c = 0) : to(t), cost(c) {}

};


int rec(int v,int dist, vector<vector<Edge>> g, vector<bool>& visited) {
	//if (visited[v]) {
	//	// �K��ς݂̏ꍇ
	//	return dist;
	//}
	//visited[v] = true;
	//if (g[v].size() == 1) {
	//	// �s�悪�Ȃ��ꍇ
	//	return dist;
	//}
	cout << "�ċA�֐��̎��s" << endl;
	visited[v] = true;
	int cost = 0;
	for (auto e : g[v]) {
		if (visited[e.to])continue;
		rec(e.to,dist + e.cost, g, visited);
		ans = max(ans, dist);
	}


	return ans;

}

signed main() {

	int n, m;
	cin >> n >> m;

	vector<vector<Edge>> g(n);

	rep(i, n) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);

	}

	vector<bool> visited(n);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, rec(i, ans, 0, g, visited));
	}
	cout << ans << endl;
	return 0;

}

