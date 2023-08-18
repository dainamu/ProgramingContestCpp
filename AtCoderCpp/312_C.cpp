#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
#define rep(i,n) for(int i =0; i<n; i++)
using P = pair<int, int>;

int main_312C() {

	int n, m;
	
	cin >> n >> m;

	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	vector<P> events;
	rep(i, n) events.push_back(P(a[i], 0));
	rep(i, m) events.push_back(P(b[i]+1, 1));
	sort(events.begin(), events.end()); // pairŒ^‚Ìƒ\[ƒg‚Íˆê‚Â–Ú‚Ì—v‘f‚Å”äŠr‚³‚ê‚éB
	int na = 0, nb = m;

	for (pair<int, int> p : events) {
		if (p.second == 0) na++; else nb--;

		if (na >= nb) {
			cout << p.first << endl;
			return 0;
		}
	}

	return 0;
}