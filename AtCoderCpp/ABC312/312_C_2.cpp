#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
#define rep(i,n) for(int i =0; i<n; i++)
using P = pair<int, int>;

int main_312C_2() {

	int n, m;

	cin >> n >> m;

	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	
	int wa = 0, ac = 1e9+1;
	while (wa + 1 < ac) {
		int wj = (wa + ac) / 2;
		int na = 0, nb = 0;
		rep(i, n) if (a[i] <= wj) na++;
		rep(i, m) if (b[i] >= wj) nb++;
		if (na >= nb) ac = wj; else wa = wj;
		
	}
	cout << ac << endl;
	
	return 0;
}