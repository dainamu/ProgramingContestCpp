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
//#include <format>
#include <stack>
#include <regex>
//#include <print>
#include<stacktrace>
#include <fstream>
/*
 * @file P23
 *
*/
using namespace std;
static void ants() {

	ifstream ifs("input.txt", ios::in);
	if (!ifs) {
		cerr << "ファイルを読込めませんでした。" << endl;
		return;
	}

	string str;
	int l, n;
	ifs >> l >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		ifs >> x[i];
	}
	for (int i = 0; i < n;i++)cout << x[i];

	ifs.close();


}