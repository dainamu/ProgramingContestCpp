#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;

int main_sample() {

    int N;
    cin >> N;
    int cnt = 0;
    while (N > 0) {
        cnt++;
        N /= 2;
    }
    cout << cnt << endl;
    return 0;
}