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
#include <bitset>
#include <queue>
#include <numeric>
#include <stack>
#include <regex>
#include<stacktrace>
#include <fstream>
//#include <print>
//#include <format>

#define rep(i, n) for(int i=0; i<(n); i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const char nl = '\n';
const int INF = 102345678;
using namespace std;
using P = pair<int, int>;
using ll = long long;
using ull = unsigned long long;


ifstream ifs;
/*
*ファイルから入力受け取る場合cinのかわりにifsをつかう
* 
* ifs >> str;
* 
*/
int fin_open() {

	string fileName;
	cin >> fileName;
	fileName = fileName + ".txt";

	ifs.open(fileName, ios::in);
	
	if (!ifs) {
		cerr << "ファイルを読込めませんでした。" << endl;
		return 1;
	}
	return 0;
}
/*
 * @file 
 * ABC 348 D
 * 
 * 
 * 
*/
/*
コメントアウト Ctrl + K → C
コメント外す   Ctrl + K → U
*/

int main() {
	IOS;

	string s;
	cin >> s;
	bool b = true;
	if(s[0] == '<' && s[s.length()-1] == '>' ){
		for(int i=1; i<s.length()-1; i++){
			if(s[i] != '='){
				b = false;
			}
		}
	}else{
		b = false;
	}
	string ans = b ? "Yes":"No";
	cout << ans << endl;
	
	// 入力
	
} 