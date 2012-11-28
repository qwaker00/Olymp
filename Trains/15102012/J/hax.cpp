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

#define N 111111

struct Tp {
    int x, y;
} a[N];
int t[N], hx[N], hy[N], hnx, hny;
int S[N];

bool ByX(const Tp& A, const Tp& B) {
    return A.x < B.x || (A.x == B.x && A.y < B.y);
}

bool ByY(const Tp& A, const Tp& B) {
    return A.y < B.y || (A.y == B.y && A.x < B.x);
}

bool ByPlus(const Tp& A, const Tp& B) {
    return A.x + A.y < B.x + B.y;
}

bool ByMinus(const Tp& A, const Tp& B) {
    return A.x - A.y < B.x - B.y;
}

int Sum(int x) {
    ++x;

    int ans = 0;
    while (x < N) {
        ans += S[x];
        x = (x | (x - 1)) + 1;
    }
    return ans;
}

void Add(int x) {
    ++x;

    while (x) {
        ++S[x];
        x &= x - 1;    
    }
}

LL CalcInv(const int* a, int n) {
    memset(S, 0, sizeof(S));
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans += Sum(a[i] + 1);
        Add(a[i]);
    }
    return ans;
}

LL Calc(const Tp* a, int n) {
    for (int i = 0; i < n;  i++) t[i] = a[i].x;
    LL a1 = CalcInv(t, n);
    for (int i = 0; i < n;  i++) t[i] = a[i].y;
    LL a2 = CalcInv(t, n);
    return a1 + a2;
}

int main() {
    freopen("john.in", "r", stdin);
    freopen("john.out", "w", stdout);

    LL ans;
    int n;

    cin >> n;
    ans = LL(n) * n * 2;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        hx[hnx++] = a[i].x;
        hy[hny++] = a[i].y;
    }
    sort(hx, hx + hnx);
    hnx = unique(hx, hx + hnx) - hx;
    sort(hy, hy + hny);
    hny = unique(hy, hy + hny) - hy;
    for (int i = 0; i < n; i++) {
        a[i].x = lower_bound(hx, hx + hnx, a[i].x) - hx;
        a[i].y = lower_bound(hy, hy + hny, a[i].y) - hy;
    }

    sort(a, a + n, ByX);
    ans = min(ans, Calc(a, n));

    sort(a, a + n, ByY);
    ans = min(ans, Calc(a, n));

    sort(a, a + n, ByPlus);
    ans = min(ans, Calc(a, n));

    sort(a, a + n, ByMinus);
    ans = min(ans, Calc(a, n));
    
    cout << min(ans, LL(n) * (n - 1) - ans) << endl;

    return 0;
}
                      