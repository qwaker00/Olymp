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

int n;
int p[100011][26];
int pred[101] = {0,-26,-1,-2,0,-3,0,-4,0,1,0,-5,0,-6,0,1,0,-7,0,-8,0,1,0,-9,0,2,0,1,0,-10,0,-11,0,1,0,2,0,-12,0,1,0,-13,0,-14,0,1,0,-15,0,3,0,1,0,-16,0,2,0,1,0,-17,0,-18,0,1,0,2,0,-19,0,1,0,-20,0,-21,0,1,0,3,0,-22,0,1,0,-23,0,2,0,1,0,-24,0,3,0,1,0,2,0,-25,0,1,0};
int pr[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int pl[101][101], pn[101];

LL Pow(LL x, LL y, LL m) {
    LL res = 1;
    while (y) {
        if (y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

char ch;
void getx(int& x) {
    while ((ch = getchar()) < '0');
    x = ch - 48;
    while ((ch = getchar()) >= '0') x = x * 10 + ch - 48;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 2; i <= 100; ++i) {
        int x = i;
        while (pred[x] >= 0) {
            pl[i][pn[i]++] = pred[x];
            x /= pr[pred[x]];
        }
        pl[i][pn[i]++] = -pred[x]-1;
    }

    getx(n);
    for (int i = 1; i <= n; ++i) {
        int x;
        getx(x);
        memcpy(p[i], p[i - 1], sizeof(p[i - 1]));
        for (int j = 0; j < pn[x]; ++j) ++p[i][pl[x][j]];
    }

    int t;
    getx(t);
    while (t--) {
        int l, r, m;
        getx(l); getx(r); getx(m);
        --l;
        LL ans = 1 % m;
        const int *prr = p[r];
        const int *pll = p[l];
        for (size_t i = 0; i < 25; ++i)
            if (prr[i] > pll[i]) 
                ans = (ans * Pow(pr[i], prr[i] - pll[i], m)) % m;
        printf("%d\n", (int)ans);
    }
    
    return 0;
}
            