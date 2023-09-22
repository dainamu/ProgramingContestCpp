#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define req(i, n) for(int i=0; i<n; i++)
using namespace std;


bool isPali(string str) {
	
	int low = 0;
	int hight = str.length() - 1;

	while (low < hight) {
		
		if (str.at(low) != str.at(hight)) {
			return false;
		}
		low++;
		hight--;
	}
	return true;
}
bool isCheck(string str, int len) {

	bool b =  false;
	for (int i = 0; i <= str.length() - len; i++) {

		string s = str.substr(i, len);
		b = isPali(s);
		if (b)break;

	}
	return b;
}
int main_320B() {

	string s;

	cin >> s;

	int max = 1;

	int len = s.length(); // •¶Žš‚Ì’·‚³

	for (int i = 0; i < s.length(); i++) {

		bool b = isCheck(s, len);

		if (b) {
			max = std::max(max, len);
			break;
		}

		len--;
	}

	cout << max << endl;

	return 0;
}