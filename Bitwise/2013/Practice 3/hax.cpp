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

struct Tp {
    int l, r;
    int add, val[3];
} T[333333];
int n, m, l, r;
char c;

void Init(int x, int l, int r) {
    T[x].l = l;
    T[x].r = r;
    T[x].val[0] = r - l + 1;
    T[x].val[1] = T[x].val[2] = T[x].add = 0;
    if (l < r) {
        Init(x + x, l, (l + r) >> 1);
        Init(x + x + 1, (l + r + 2) >> 1, r);
    }
}

inline int Zero(int x, int l, int r, int add = 0) {
    if (T[x].l > r || T[x].r < l) return 0;
    add += T[x].add;
    if (T[x].l >= l && T[x].r <= r) {
        return T[x].val[(300000000 - add) % 3];
    }
    return Zero(x + x, l, r, add) + Zero(x + x + 1, l, r, add);
}

void Inc(int x, int l, int r) {
    if (T[x].l > r || T[x].r < l) return;
    if (T[x].l >= l && T[x].r <= r) {
        ++T[x].add;
        return;
    }
    Inc(x + x, l, r);
    Inc(x + x + 1, l, r);
    T[x].val[0] = T[x + x].val[(300000000 - T[x + x].add) % 3] + T[x + x + 1].val[(300000000 - T[x + x + 1].add) % 3];
    T[x].val[1] = T[x + x].val[(300000001 - T[x + x].add) % 3] + T[x + x + 1].val[(300000001 - T[x + x + 1].add) % 3];
    T[x].val[2] = T[x + x].val[(300000002 - T[x + x].add) % 3] + T[x + x + 1].val[(300000002 - T[x + x + 1].add) % 3];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d\n", &n, &m);
    Init(1, 0, n - 1);
    while (m--) {
        scanf("%c%d%d\n", &c, &l, &r);
        if (c == 'Q')
            printf("%d\n", Zero(1, l, r));
        else
        if (c == 'T')
            Inc(1, l, r);
    }    
    
    return 0;
}
