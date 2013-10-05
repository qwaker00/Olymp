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


#define N 11111

int t, m, n, d, h, cc;
int super[N], p[N], reg[N], net[N], z;
char regcode[222][2222];
char buf[11111];
int b[555555][10], bn = 0;
int town[555555];
int cost[4][4];

int type1(int t) {
    if (reg[t] == h) return 0;
    if (net[reg[t]] && super[reg[t]] == super[h]) return 1;
    if (net[reg[t]]) return 2;
    return 3;
}

int type2(int from, int to) {
    if (from == to) return 0;
    if (reg[from] == reg[to]) return 1;
    if (net[reg[to]]) return 2;
    return 3;
}

void add(const char * s, int t) {
    int cur = 0;
    while (*s) {        
        char ch = *s - '0';
        ++s;
        if (!b[cur][ch]) b[cur][ch] = ++bn;
        cur = b[cur][ch];
    }
    town[cur] = t;
}
int gettown(const char * s) {
    int cur = 0;
    while (*s) {
        char ch = *s - '0';
        ++s;

        if (!b[cur][ch]) return -1;
        cur = b[cur][ch];
        if (town[cur]) {
            return town[cur];
        }
    }
    return -1;
}

int main() {
    freopen("called.in", "r", stdin);
    freopen("called.out", "w", stdout);


    scanf("%d%d%d%d", &t, &m, &n, &d);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%s", &super[i], regcode[i]);
//        addr(buf, i);
    }
    for (int i = 1; i <= t; ++i) {
        scanf("%d%d", &reg[i], &p[i]);
        if (p[i] == 0) {            
            add(regcode[reg[i]], i);
        } else {
            strcpy(buf, regcode[reg[i]]);
            int ll = strlen(regcode[reg[i]]);
            for (int j = 0; j < p[i]; ++j) {
                scanf("%s", buf + ll);
                add(buf, i);
            }
        }
    }
    scanf("%d%d", &h, &z);
    for (int i = 0; i < z; ++i) {
        int x;
        scanf("%d", &x);
        net[x] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &cost[i][j]);
        }
    }

    LL ans = 0;
    scanf("%d", &cc);
    for (int i = 0; i < cc; ++i) {
        int from, l;
        scanf("%d%s%d", &from, buf, &l);
        int to = gettown(buf);

        if (to == -1) continue;
        ans += LL(l) * cost[type1(from)][type2(from, to)];
    }
    cout << ans << endl;
    
    return 0;
}
