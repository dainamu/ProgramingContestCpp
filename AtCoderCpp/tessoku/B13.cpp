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

int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ↑ → ↓ ← 右上 右下 左下 左上  中心
int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };

ll N, K;
ll A[100009];
ll S[100009]; // 累積和
ll R[100009]; // 左端がきまったとき、右端はどこまでいけるか。


// A[l] からA[r]までの合計値
ll sum(int l, int r) {
	return S[r] - S[l - 1];
}
signed main() {

	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// 累積和をとる
	S[0] = 0;
	for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

	// 尺取り法
	for (int i = 1; i <= N; i++) {

	}


	return 0;

}

