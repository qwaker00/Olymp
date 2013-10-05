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

template<typename T>
T gcd(T x, T y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        LL ans1 = 0;
        int last = n;
        int fin = (int)sqrt(n);
        for (int i = 1; last > fin ;++i) {
            int nxt = n / (i + 1);
            ans1 += LL(i) * (last - nxt);
            last = nxt;
        }
        while (last > 0) {
            ans1 += n / last;
            --last;
        }
        LL ans2 = LL(n) * n;
        LL g = gcd(ans1, ans2);
        cout << ans1 / g << '/' << ans2 / g << '\n';
    }    
    
    return 0;
}
