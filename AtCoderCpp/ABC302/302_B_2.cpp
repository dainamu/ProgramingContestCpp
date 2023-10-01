#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;

int di[] = {-1,0,1,0,-1,1,1,-1,0}; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
int dj[] = {0,1,0,-1,1,1,-1,-1,0};

int main_302B_2() {

	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	rep(si, h)rep(sj, w) {
		string T = "snuke";

		rep(v, 8) {
		int i = si; int j = sj;
			rep(k, 5) {
				if (i < 0 || i>= h || j < 0 || j >= w) break;
				if (s[i][j] != T[k]) break;
				if (k == 4) {
					// found
					i = si; j = sj;
					rep(nk, 5) {
						printf("%d %d\n", i + 1, j + 1);
						i += di[v]; j += dj[v];
					}
					return 0;
				}
				i += di[v]; j += dj[v];
			}


		}
	}

	return 0;
}


