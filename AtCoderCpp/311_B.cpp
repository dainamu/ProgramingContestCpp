#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main_311B() {

	int n;
	int d;
	cin >> n >> d;

	const int dc = d;

	vector<string> s;

	for (int i = 0; i < n; i++) {

		string tmp;
		cin >> tmp;

		for (int j = 0; j < d; j++) {
			if (tmp.at(j) == 'o') {
				tmp.at(j) = '1';
			}
			else {
				tmp.at(j) = '0';
			}
		}

		s.push_back(tmp);

	}


	string str_tmp(100, '1');
	auto bit_tmp = bitset<100>(str_tmp);


	for (int i = 0; i < n; i++) {
		auto bits_a = bitset<100>(s[i]);
		bit_tmp = (bit_tmp & bits_a);
	}

	string bit_s = bit_tmp.to_string();

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < bit_s.size(); i++) {
		
		if (bit_s.at(i) == '1') {
			cnt++;
		}
		else {
			cnt = 0;
		}

		ans = max(cnt, ans);

	}

	cout << ans << endl;
	return 0;
}