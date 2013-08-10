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

#define N 111111

vector< pair< int, vector<int> > > g[N];
vector< pair< int, int > > fr[N];
vector< int > gg[N];
int n, x, y, l, m;
int wasmin[N], ansmin[N];
int wasmax[N], ansmax[N];

#define INF 2147483647
#define THRESH 314000000

int finish[N];
int was[N];

int GetMin(int x) {
    if (wasmin[x] == 1) return INF;
    if (wasmin[x] == 2) return ansmin[x];
    wasmin[x] = 1;

    int ans = INF;
    for (int i = 0; i < g[x].size(); ++i) {
        int sc = g[x][i].first;
        for (int j = 0; j < g[x][i].second.size(); ++j) {
            if (!finish[g[x][i].second[j]]) {
                sc = INF;
                break;
            }
            int v = GetMin(g[x][i].second[j]);
            if (v == INF) {
                sc = INF;
                break;
            } else {
                sc += v;
                if (sc > THRESH) sc = THRESH;
            }
        }
        if (sc == INF) continue;
        if (sc < ans) ans = sc;
    }

    wasmin[x] = 2;
    return ansmin[x] = ans;
}

int GetMax(int x) {
    if (wasmax[x] == 1) return INF;
    if (wasmax[x] == 2) return ansmax[x];
    wasmax[x] = 1;

    int ans = 0;
    for (int i = 0; i < g[x].size(); ++i) {
        int sc = g[x][i].first;
        for (int j = 0; j < g[x][i].second.size(); ++j) {
            if (!finish[g[x][i].second[j]]) {
                sc = 0;
                break;
            }

            int v = GetMax(g[x][i].second[j]);
            if (v == INF) {
                sc = INF;
            } else {
                if (sc == INF) continue;
                sc += v;
                if (sc > THRESH) sc = THRESH;
            }
        }
        if (sc == INF) {
            ans = INF;
            break;
        }
        if (sc > ans) ans = sc;
    }

    wasmax[x] = 2;
    return ansmax[x] = ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    queue<int> q;

    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &x, &l);

        int score = 0;
        vector<int> v;
        for (int j = 0; j < l; ++j) {
            scanf("%d", &y);
            if (y == -1) score++;else { 
                v.push_back(y);
                fr[y].push_back( make_pair(x, g[x].size()) );
            }
        }
        if (score == l) {
            q.push(x);
            finish[x] = 1;
        }
        g[x].push_back(make_pair(score, v));        
        gg[x].push_back(v.size());
    }

    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (was[x]) continue;
        was[x] = 1;
        GetMin(x);
        GetMax(x);
        for (int i = 0; i < fr[x].size(); ++i) {
            if (--gg[ fr[x][i].first ] [ fr[x][i].second ] == 0) {
                q.push(fr[x][i].first);
                finish[fr[x][i].first] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; ++i)
        if (!finish[i]) {
            puts("-1 -1");
        } else {
            int mi = GetMin(i), ma = GetMax(i);
            if (mi > THRESH) mi = THRESH;
            if (ma == INF) ma = -2; else
                if (ma > THRESH) ma = THRESH;
            printf("%d %d\n", mi, ma);
        }

    return 0;
}
