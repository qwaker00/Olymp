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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


LL solve() {
    LL ans = 0;
    LL a, b, k;
    cin >> a >> b >> k;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if ((i & j) < k) {
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int it = 1; it <= T; ++it) {
        cout << "Case #" << it << ": " << solve() << endl;
    }    
    
    return 0;
}
