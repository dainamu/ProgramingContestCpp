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
#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()


using namespace std;
using ll = long long;
using ull = unsigned long long;

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // �� �� �� �� �E�� �E�� ���� ����  ���S
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

ll N, K;
ll A[100009];
ll S[100009]; // �ݐϘa
ll R[100009]; // ���[�����܂����Ƃ��A�E�[�͂ǂ��܂ł����邩�B


// A[l] ����A[r]�܂ł̍��v�l
ll sum(int l, int r) {
	return S[r] - S[l - 1];
}
signed main() {

	// ����
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// �ݐϘa���Ƃ�
	S[0] = 0;
	for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

	// �ڎ��@
	for (int i = 1; i <= N; i++) {

	}


	return 0;

}

