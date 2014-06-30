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

LL gcd(LL x, LL y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        LL num = LL(n / 2) * ((m + 1) / 2) + LL(m / 2) * ((n + 1) / 2);
        LL denum = LL(n) * m;
        LL g = gcd(num, denum);
        cout << (num / g) << "/" << (denum / g) << endl;
    }
    
    return 0;
}
