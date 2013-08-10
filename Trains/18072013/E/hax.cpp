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

const int N = 555;

vector<pair<int, int> > g[N];
vector<int> ans[N];
int d[N];


int main() {
    freopen("defence.in", "r", stdin);
    freopen("defence.out", "w", stdout);
    
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);

    --s; --t;

    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);

        --a; --b;
        g[a].push_back(make_pair(b, i));
        g[b].push_back(make_pair(a, i));
    }

    queue<int> q;
    memset(d, 63, sizeof(d));

    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < g[x].size(); ++i) {
            int y = g[x][i].first;
            int num = g[x][i].second;

            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    } 

    for (int x = 0; x < n; ++x) 
        for (int i = 0; i < g[x].size(); ++i)
            if (d[ g[x][i].first ] > d[x]) {
                ans[ d[x] ].push_back(g[x][i].second);
            }

    int cans = d[t];
    printf("%d\n", cans);
    for (int i = 0; i < cans; ++i) {
        printf("%d", ans[i].size());
        for (int j = 0; j < ans[i].size(); ++j) {
            printf(" %d", ans[i][j]);
        }
        puts("");
    }

    return 0;

}
