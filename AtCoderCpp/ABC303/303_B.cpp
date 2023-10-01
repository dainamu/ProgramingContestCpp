#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_303B() {

	int n, m; cin >> n >> m;
	vector<vector<int>> a(m, vector<int>(n));

	req(i, m) {
		req(j, n) {
			cin >> a[i][j];
		}
	}
	
	vector<pair<int, int>> pars;


	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pair<int, int> p(i,j);
			pars.push_back(p);
	
		}
	}

	vector<bool> vec(pars.size());
	for (int k = 0; k < m; k++) {
		for (int p = 0; p < n - 1; p++) {
			int t1 = a[k][p];
			int t2 = a[k][p + 1];

			for (int l = 0; l < pars.size(); l++) {
				pair<int, int> tmp(pars[l].first, pars[l].second);

				if ((tmp.first == t1 && tmp.second == t2) || (tmp.first == t2 && tmp.second == t1)) {
					vec[l] = true;
				}
			}

		}
	}
	size_t n_count = std::count(vec.begin(), vec.end(), false);
	cout << n_count << endl;
	return 0;
}