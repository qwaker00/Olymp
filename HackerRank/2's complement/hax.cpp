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

inline LL res(unsigned a) {
    LL ans = 0;
    LL A = a;
    for (unsigned sh = 0; sh <= 31; ++sh) {
        ans += (A >> (sh + 1)) * (1ull << sh);
        if (A & (1ull << sh)) ans += (A & ((1ull << (sh + 1)) - 1)) - (1ull << sh) + 1;
    }
    return ans;
}

inline LL res(unsigned A, unsigned B) {
    if (B < A) return 0;
    return res(B) - res(A - 1);
}

int main() {
//    freopen(".in", "r", stdin);
    int A, B;
    int T;
    cin >> T;
    while (T--) {
        cin >> A >> B;    
        if (A < 0 && B < 0)
            cout << res(A, B) << endl;else
        if (A <= 0)
            cout << res(A, -1) + res(1, B) << endl;else
        cout << res(A, B) << endl;
    }
    return 0;
}
