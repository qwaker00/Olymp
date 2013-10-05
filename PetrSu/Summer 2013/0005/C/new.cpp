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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 422222
#define NONE -2147483646

int n, m, w[N];
int pr[N];
int was[N];
int d[N];
vector<int> g[N];


void HLDoT(int x) {
    was[x] = true;
    for (size_t i = 0; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (!was[y]) {
            pr[y] = x;
            d[y] = d[x] + 1;
            HLDoT(y);
        }
    }
}

int main() {
    #ifdef DEBUG
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    #endif
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    pr[1] = 0;
    HLDoT(1);

    while (m--) {
        int t, a, b, c;
        scanf("%d%d%d%d", &t, &a, &b, &c);
        if (t == 1) {
            while (d[a] > d[b]) {
                w[a] = c;
                a = pr[a];
            }
            while (d[b] > d[a]) {
                w[b] = c;
                b = pr[b];
            }
            while (a != b) {
                w[a] = c;
                w[b] = c;
                a = pr[a];
                b = pr[b];
            }
            w[a] = c;
        } else {
            vector<int> v1, v2;
            while (d[a] > d[b]) {
                v1.push_back(w[a]);
                a = pr[a];
            }
            while (d[b] > d[a]) {
                v2.push_back(w[b]);
                b = pr[b];
            }
            while (a != b) {
                v1.push_back(w[a]);
                v2.push_back(w[b]);
                a = pr[a];
                b = pr[b];
            }
            v1.push_back(w[a]);
            reverse(v2.begin(), v2.end());
            for (int i = 0; i < v2.size(); ++i) v1.push_back(v2[i]);

            #ifdef DEBUG
            for (int i = 0; i < v1.size(); ++i) cerr << v1[i] << ' ';
            cerr << '\n';
            #endif

            int ans = v1[0];
            int ps = v1[0];
            int lastps = min(0, v1[0]);
            for (int i = 1; i < v1.size(); ++i) {
                ps += v1[i];
                if (ps - lastps > ans) ans = ps - lastps;
                if (ps < lastps) lastps = ps;
            }
            printf("%d\n", ans);
        }
    }
    cerr << clock() << endl;
    
    return 0;
}
