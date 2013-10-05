#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

#include <ext/rope>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

       int n, ans = 0; 
    cin >> n;
    int last = 0, f = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == last + 1) {
            ++ans;
            if (!f) ++ans, f = 1;
        } else f = 0;
        last = x;
    }
    cout << ans << endl;

    return 0;
}
