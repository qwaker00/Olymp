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

int n, m, k;
struct Tp {
    int x, y;
} e[11111];
int d1[10011][505], d2[10011][505];
int id[505], pr[505];

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

inline int CalcMerge(const int* d1, const int* d2) {
    memcpy(pr, d1, sizeof(pr[0]) * (n + 1));
    for (int i = 1; i <= n; ++i) {
        if (pr[d2[i]] != pr[i])
            pr[fs(i)] = fs(d2[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (pr[i] == i) ++cnt;
    return cnt; 
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d", &n, &m);


    for (int i = 1; i <= n; ++i) {
        id[i] = i;
        d1[0][i] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &e[i].x, &e[i].y);

        int ix = id[e[i].x];
        int iy = id[e[i].y];
        for (int j = 1; j <= n; ++j) {
            if (id[j] == ix) {
                id[j] = iy;
            }
            d1[i + 1][j] = id[j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        id[i] = i;
        d2[m][i] = i;
    }
    for (int i = m - 1; i >= 0; --i) {
        int ix = id[e[i].x];
        int iy = id[e[i].y];
        for (int j = 1; j <= n; ++j) {
            if (id[j] == ix) {
                id[j] = iy;
            }
            d2[i][j] = id[j];
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", CalcMerge(d1[l - 1], d2[r]));
    }
    
    return 0;
}
