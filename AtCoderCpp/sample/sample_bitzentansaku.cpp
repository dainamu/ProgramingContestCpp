#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
void bitsubnet(int N) {
	for (int mask = 0; mask < (1 << N); mask++) {
		vector<int> subnet;
		for (int i = 0; i < N; i++) {
			if (mask & (1 << i)) {
				subnet.push_back(i);
			}
		}

		cout << "Subnet";
		for (int elem : subnet) {
			cout << elem << " ";
		}
		cout << endl;

	}


}

int main() {
	
	int k;
	cin >> k;
	vector<int> s{ 0,1,2,3,4,5,6,7,8,9 };
	vector<string> numbers;
	vector<ll> ans;
	for (int i = 1; i < (1 << 10); i++) {  // 0`((2‚Ì10æ)-1)
		string str;
		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				str = to_string(s[j]) + str;
			}
		}

		//if (i == k) {
			//reverse(ans.begin(), ans.end());
			//for (int k = 0; k < ans.size(); k++) {
			//	cout << ans[k];
			//}
			//cout << endl;
		//}
		//cout << str << endl;
		ll num = atoll(str.c_str());
		ans.push_back(num);
	}

	sort(ans.begin(), ans.end());
	//for (ll n : ans) cout << n << endl;
	cout << ans[k] << endl;

	return 0;
}