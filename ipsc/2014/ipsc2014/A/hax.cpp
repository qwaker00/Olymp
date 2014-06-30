#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char _s[111111];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    scanf("%d\n", &T);
    while (T--) {
        gets(_s);        
        string s2 = _s;
        gets(_s);
        string s1 = _s;
        gets(_s);

        string ans;
        bool found = 0;
        for (int i = s1.length(); i >= 0; --i) {
            if (s1.length() - i + s2.length() - i < 1 + s2.length() && s1.substr(0, i) == s2.substr(0, i)) {
                for (int j = 0; j < s1.length() - i; ++j) ans += '<';
                for (int j = i; j < s2.length(); ++j) ans += s2[j];
                ans += "*";
                found = 1;
                break;
            }
        }
        if (!found) {
            ans = string("*") + s2 + "*";
        }
        cout << ans << endl;
    }
    
    return 0;
}
