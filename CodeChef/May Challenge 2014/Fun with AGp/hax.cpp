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

int P1;
int P2;

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
};

int R;
TInt PowR[111111], SumR[111111];

struct Tree {
    int left, right;
    TInt s;
    TInt d;
    TInt sumDown;
    TInt sumCur;
} T[444444];

void Init(int x, int l, int r, int* a) {
    T[x].left = l;
    T[x].right = r;
    T[x].d = TInt();
    if (l < r) {
        Init(x + x, l, (r + l) >> 1, a);
        Init(x + x + 1, (r + l + 2) >> 1, r, a);
        T[x].s = TInt();
        T[x].sumCur = TInt();
        T[x].sumDown = T[x + x].sumDown + T[x + x].sumCur + T[x + x + 1].sumDown + T[x + x + 1].sumCur;
    } else {
        T[x].s = a[l];
        T[x].sumDown = TInt();
        T[x].sumCur = T[x].s;
    }
}

inline TInt CalcSum(const TInt& a, const TInt& d, int n) {
    if (n == 1) return a;
    if (n == 2) return a + (a + d) * R;
    if (n & 1) {
        return CalcSum(a, d, n - 1) + (a + d * (n - 1)) * PowR[n - 1];
    } else {
        TInt t = CalcSum(a, d, n >> 1);
        return t + (t + d * SumR[(n >> 1) - 1] * (n >> 1)) * PowR[n >> 1];
    }
}

inline TInt CalcSum(const TInt& a, const TInt& d, int l, int r) {
    if (l == 0)
        return CalcSum(a, d, r + 1);
    if (l == r)
        return (a + d * r) * PowR[r];
    if (l + 1 == r)
        return (a + d * r) * PowR[r] + (a + d * l) * PowR[l];
    return CalcSum(a, d, r + 1) - CalcSum(a, d, l);
}

inline int CalcSumP1(const int a, const int d, int n) {
    if (n == 1) return a;
    if (n == 2) return (a + LL(a + d) * R) % P1;
    if (n & 1) {
        return (CalcSumP1(a, d, n - 1) + ((a + LL(d) * (n - 1)) % P1) * PowR[n - 1].v1) % P1;
    } else {
        int t = CalcSumP1(a, d, n >> 1);
        return (t + ((t + ((LL(d) * SumR[(n >> 1) - 1].v1) % P1) * (n >> 1)) % P1) * PowR[n >> 1].v1) % P1;
    }
}

inline int CalcSumP1(int a, int d, int l, int r) {
    if (l == 0)
        return CalcSumP1(a, d, r + 1);
    if (l == r)
        return (((a + LL(d) * r) % P1) * PowR[r].v1) % P1;
    return (CalcSumP1(a, d, r + 1) - CalcSumP1(a, d, l) + P1) % P1;
}

void Add(int x, int l, int r, const TInt& s, const TInt& d) {
    if (l > T[x].right || r < T[x].left) return;
    if (l <= T[x].left && r >= T[x].right) {
        int start = T[x].left - l;
        const TInt& fakeS = PowR[start] * (s + d * start);
        const TInt& fakeD = PowR[start] * d;
        T[x].s = T[x].s + fakeS;
        T[x].d = T[x].d + fakeD;
        T[x].sumCur = CalcSum(T[x].s, T[x].d, T[x].right - T[x].left + 1);
        return;
    }
    Add(x + x, l, r, s, d);
    Add(x + x + 1, l, r, s, d);
    T[x].sumDown = T[x + x].sumDown + T[x + x].sumCur + T[x + x + 1].sumDown + T[x + x + 1].sumCur;
}

int GetP2(int x, int l) {
    if (T[x].left == l && T[x].right == l) return (T[x].sumDown.v2 + T[x].sumCur.v2) % P2;
    if (l * 2 <= (T[x].left + T[x].right))
        return (GetP2(x + x, l) + ((T[x].s.v2 + LL(T[x].d.v2) * (l - T[x].left)) % P2) * PowR[l - T[x].left].v2 ) % P2;
    return (GetP2(x + x + 1, l) + ((T[x].s.v2 + LL(T[x].d.v2) * (l - T[x].left)) % P2) * PowR[l - T[x].left].v2 ) % P2;
}

TInt Sum(int x, int l, int r) {
    if (l > T[x].right || r < T[x].left) return TInt();
    if (l <= T[x].left && r >= T[x].right) return T[x].sumDown + T[x].sumCur;
    TInt s = CalcSum(T[x].s, T[x].d, max(l, T[x].left) - T[x].left, min(r, T[x].right) - T[x].left);
    s = s + Sum(x + x, l, r);
    s = s + Sum(x + x + 1, l, r);
    return s;
}

int SumP1(int x, int l, int r) {
    if (l > T[x].right || r < T[x].left) return 0;
    if (l <= T[x].left && r >= T[x].right) return (T[x].sumDown.v1 + T[x].sumCur.v1) % P1;
    int s = CalcSumP1(T[x].s.v1, T[x].d.v1, max(l, T[x].left) - T[x].left, min(r, T[x].right) - T[x].left);
    s = s + SumP1(x + x, l, r);
    s = s + SumP1(x + x + 1, l, r);
    return s % P1;
}

int a[111111];

inline void getx(int& x) {
    char ch;
    while ((ch = getchar()) < '0');
    x = ch - 48;
    while ((ch = getchar()) >= '0') x = x * 10 + ch - 48;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T; 
    scanf("%d", &T);
    while (T--) {
        int n, q;
        scanf("%d%d%d%d%d", &n, &q, &R, &P1, &P2);

        PowR[0] = 1;
        SumR[0] = 1;
        for (int i = 1; i <= n; ++i) {
            getx(a[i]);
            PowR[i] = PowR[i - 1] * R;
            SumR[i] = SumR[i - 1] + PowR[i];
        }
        Init(1, 1, n, a);
        
        int t, s, d, x, y;
        TInt newv, v;
        while (q--) {
            getx(t);
            switch (t) {
                case 0:
                    getx(s);
                    getx(d);
                    getx(x);
                    getx(y);
//                    scanf("%d%d%d%d", &s, &d, &x, &y);
                    Add(1, x, y, s, d);
                break;

                case 1:
                    getx(x);
                    getx(y);
//                    scanf("%d%d", &x, &y);
                    v = Sum(1, x, x);
                    newv = PowMod(v.v2, y, P2);
                    Add(1, x, x, newv - v, 0);
                break;

                case 2:
                    getx(x);
                    getx(y);
//                    scanf("%d%d", &x, &y);
//                    printf("%d:%d:%d\n", T, q, Sum(1, x, y).v1);
                    printf("%d\n", SumP1(1, x, y));
                break;
            }
        }
    }
//    cerr << clock() << endl;    
    return 0;
}
