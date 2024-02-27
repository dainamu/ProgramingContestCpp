#include <iostream>
#include <vector>
#include <algorithm>

#define req(i, n) for(int i=0; i<n; i++)

using namespace std;
using ll = long long;
namespace sample {
    int di[] = { -1,0,1,0,-1,1,1,-1,0 }; // ª ¨ « © ‰Eã ‰E‰º ¶‰º ¶ã  ’†S
    int dj[] = { 0,1,0,-1,1,1,-1,-1,0 };
}
int sample_a() {

    string s = "abc";
    string s2 = "efg";
    string s3 = s + s2;
    cout << s3 << endl;

    return 0;
}