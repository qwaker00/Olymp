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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

ULL CanMask(ULL msk, int l, LL x) {
    if (x == 0 && l > 0 && msk > 0) return false;
    if (l == 0) {
        return x >= 0;
    }
    return CanMask(msk, l - 1, x / 2);
}

ULL Worst(LL x, int n) {
    ULL msk = 0;
    for (int i = 0; i < n; ++i) {
        if ((1ll << (i + 1)) <= x + 1) {
            msk = (msk << 1) + 1;
        } else {
            msk = (msk << 1) + 0;
        }
    }
    return msk;
}

ULL Best(LL x, int n) {
    ULL msk = 0;
    for (int i = 0; i < n; ++i) {
        if ((1ll << (i + 1)) <= (1ll << n) - x) {
            msk = (msk << 1) + 0;
        } else {
            msk = (msk << 1) + 1;
        }
    }
    return msk;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        ULL n, p;
        cin >> n >> p;

        cout << "Case #" << __it << ": ";

        ULL left = 0;
        ULL right = (1ll << n) - 1;
        while (left < right) {
            ULL center = (left + right + 1) >> 1;
            if (Worst(center, n) < p) left = center; else right = center - 1;
        }
        cout << left << " ";

        left = 0;
        right = (1ll << n) - 1;
        while (left < right) {
            ULL center = (left + right + 1) >> 1;
            if (Best(center, n) < p) left = center; else right = center - 1;
        }
        cout << left << endl;
    }                                       
    
    return 0;
}
