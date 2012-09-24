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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

LL k, m, l, r;
int it = 0;
LL cnt, ans = 1, MOD;
LL fibind = 1;

typedef LL matrix[2][2];

matrix M, A, T;

inline void Mul(matrix& c, matrix& a, matrix& b) {
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < 2; ++k) c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
        }
}

inline void chk(LL d) {
        LL start = l;
        LL finish = r - (r % d);  

        if (l % d) start += d - (l % d);

        if (finish < start) cnt = 0;else cnt = (finish - start) / d + 1;
        if (cnt >= k && d > fibind) {
            fibind = d;
        }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> MOD >> l >> r >> k;
                
    LL lo = max(1ll, (r - l + 1) / k - 1);
    LL hi = (r - l + 1) / (k - 1) + 1;
    for (int it = 0; it <= 5000000 && hi - it > 0; ++it) {
        chk(lo + it);
        chk(hi - it);
    }
    cnt = fibind;
//    cerr << cnt << endl;

    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    A[0][0] = 1;
    A[1][1] = 1;
    cnt--;
    while (cnt > 0)  {
        if (cnt & 1) { 
            Mul(T, A, M);
            memcpy(A, T, sizeof(T));
        }
        Mul(T, M, M);
        memcpy(M, T, sizeof(T));
        cnt >>= 1;
    }
    cout << A[0][0] % MOD << endl;
//    cerr << clock() << endl;
    
    return 0;
}
