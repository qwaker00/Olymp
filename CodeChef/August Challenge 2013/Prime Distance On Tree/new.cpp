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

#define N 50055
#define LGN 19
#define ITER 50000000

int n, v[N + N], timer = 0, first[N], x, y, d[N], f[LGN][N + N], lg[N + N];
vector<int> g[N];
int was[N], isprime[N];

void dfs(int x) {
    was[x] = 1;
    v[timer++] = x;
    first[x] = timer - 1;
    for (size_t i = 0; i < g[x].size(); ++i) if (!was[g[x][i]]) {
        d[g[x][i]] = d[x] + 1;
        dfs(g[x][i]);
        v[timer++] = x;
    }
}
inline int lcp(int x, int y) {
    x = first[x]; y = first[y];
    if (x > y) swap(x, y);
    int t = lg[y - x + 1];
    return (d[ f[t][x] ] < d[ f[t][y - (1 << t) + 1]]) ? f[t][x] : f[t][y - (1 << t) + 1];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int primec = 0;
    isprime[1] = 1;
    for (int i = 2; i <= n; ++i) if (!isprime[i]) {
        ++primec;
        for (int j = i + i; j <= n; j += i) isprime[j] = 1;
    }
    cerr << primec << endl;

    dfs(1);
    for (int i = 0; i < timer; ++i) f[0][i] = v[i];    
    for (int j = 0; (1 << (j + 1)) <= timer; ++j)
        for (int i = 0; i + (1 << j) <= timer; ++i)
            f[j + 1][i] = (d[ f[j][i] ] < d[ f[j][i + (1 << j)]]) ? f[j][i] : f[j][i + (1 << j)];
    lg[1] = 0;
    for (int i = 2; i <= timer; ++i) lg[i] = lg[i >> 1] + 1;

    int ans = 0;
    LL denum = LL(n) * (n - 1) / 2;
    if (denum <= ITER) {
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j) {
                int x = lcp(i, j);
                ans += isprime[d[i] - d[x] + d[j] - d[x]];
            }
    } else {
        for (int i = 0; i < ITER; ++i) {
            int x = rand();
            int y = rand();            
            int z = lcp(x, y);
            ans += isprime[d[x] - d[z] + d[y] - d[z]];
        }
    }

    cout.precision(12);
    cout << fixed;
    cout << LD(denum - ans) / denum << endl;
    cerr << clock() << endl;
    
    return 0;
}
