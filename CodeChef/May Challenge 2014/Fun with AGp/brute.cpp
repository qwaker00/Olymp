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


int P1, P2, R;

int PowMod(int x, int y, int m) {
    int res = 1;
    while (y) {
        if (y & 1)
            res = (LL(res) * x) % m;
        x = (LL(x) * x) % m;
        y >>= 1;
    }
    return res;
}

struct TInt {
    int v1;
    int v2;

    TInt() {
        v1 = v2 = 0;
    }

    template<typename T>
    TInt(const T& x) {
        v1 = x % P1;
        v2 = x % P2;
    }

    template<typename T>
    TInt(const T& x1, const T& x2) {
        v1 = x1 % P1;
        v2 = x2 % P2;
    }

    TInt operator+(const TInt& b) const {
        return TInt(v1 + b.v1, v2 + b.v2);
    }

    TInt operator-(const TInt& b) const {
        return TInt(v1 - b.v1 + P1, v2 - b.v2 + P2);
    }

    TInt operator*(const TInt& b) const {
        return TInt(LL(v1) * b.v1, LL(v2) * b.v2);
    }

    TInt rev() const {
        return TInt(PowMod(v1, P1 - 2, P1), PowMod(v2, P2 - 2, P2));
    }
};

TInt a[222222];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T; 
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d%d%d%d%d", &n, &q, &R, &P1, &P2);

        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            a[i] = x;
        }
        
        int t, s, d, x, y;
        TInt S, Rr;
        while (q--) {
            scanf("%d", &t);
            switch (t) {
                case 0:
                    scanf("%d%d%d%d", &s, &d, &x, &y);
//                    if (T != 22) break;

                    S = s, Rr = 1;
                    for (int i = x; i <= y; ++i) {
                        a[i] = a[i] + S * Rr;
                        S = S + d;
                        Rr = Rr * R;
                    }
                break;

                case 1:
                    scanf("%d%d", &x, &y);
//                    if (T != 22) break;
                    a[x] = PowMod(a[x].v2, y, P2);
                break;

                case 2:
                    scanf("%d%d", &x, &y);
//                    if (T != 22) break;
                    TInt Res = 0;
                    for (int i = x; i <= y; ++i) {
                        Res = Res + a[i];
                    }
//                    printf("%d:%d:%d\n", T, q, Res.v1);                    
                    printf("%d\n", Res.v1);                    
                break;
            }
        }
    }
    
    return 0;
}
