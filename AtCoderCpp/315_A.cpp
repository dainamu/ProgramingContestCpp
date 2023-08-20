#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)
using namespace std;

int main_315A() {

	string s;
	cin >> s;

	vector<char> word;
	vector<bool> jude(s.length(), true);

	word.push_back('a');
	word.push_back('e');
	word.push_back('i');
	word.push_back('o');
	word.push_back('u');
	
	req(i, s.length()) {
		req(j, word.size()) {
			if (s.at(i) == word.at(j)) {
				jude.at(i) = false;
			}
		}
	}

	req(i, s.length()) {

		if (jude.at(i)) {
			cout << s.at(i);
		}
	}

	cout << endl;

	return 0;
}