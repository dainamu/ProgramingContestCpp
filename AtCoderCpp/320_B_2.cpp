#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;

int main_320B_2() {

	string s;

	cin >> s;

	for (int i = s.size(); i > 1; i--) { // iを文字数で初期化してからデクリメント
		for (int start = 0; start + i <= s.size(); start++) { // startを0で初期化、文字数分ループ

			string str = s.substr(start, i); // 最初は文字全部から
			string strR = str; // リバース用文字
			reverse(strR.begin(), strR.end()); // 文字列をリバース

			if (strR == str) {
				// リバースした文字列と比較
				cout << i << endl;
				return 0;
			}

		}

	}
	
	cout << 1 << endl;
	return 0;
}