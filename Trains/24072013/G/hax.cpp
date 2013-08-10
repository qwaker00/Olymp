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

int n, m;
vector<int> gg[444];
vector<int> g[444];
int ans = 0;
int ans2 = 0;
int D[444], P[444], was[444];
int flow[444][444], cost[444][444], cap[444][444], w[444];

int Add(int x, int y, int fl) {
    cost[x][y] = -fl;
    cost[y][x] = fl;
    flow[x][y] = fl;
    cap[x][y] = 1;
    flow[y][x] = -fl;
    cap[y][x] = 0;
    gg[y].push_back(x);
}

int main() {
    freopen("keeper.in", "r", stdin);
    freopen("keeper.out", "w", stdout);


    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            g[i].push_back(n + x);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        if (w[i] != 0) {
            ++ans;
            was[w[i]] = true;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < g[i].size(); ++j) {
            Add(i, g[i][j], w[i] == g[i][j] - n);
        }
    }
    for (int X = 1; X <= n; ++X) {
        int tf = 0;
        for (int i = 0; i < g[X].size(); ++i) tf += flow[X][g[X][i]];
        for (int i = 0; i < gg[X].size(); ++i) tf += flow[X][gg[X][i]];
        if (tf > 0) continue;

        memset(D, 127, sizeof(D));
        queue<int> q;
        D[X] = 0;
        q.push(X);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 0; i < g[x].size(); ++i) {
                int y = g[x][i];
                if (cap[x][y] - flow[x][y] > 0 && D[x] + cost[x][y] < D[y]) {
                    D[y] = D[x] + cost[x][y];
                    P[y] = x;
                    q.push(y);
                }
            }
            for (int i = 0; i < gg[x].size(); ++i) {
                int y = gg[x][i];
                if (cap[x][y] - flow[x][y] > 0 && D[x] + cost[x][y] < D[y]) {
                    D[y] = D[x] + cost[x][y];
                    P[y] = x;
                    q.push(y);
                }
            }
        }
        int mi = 2e9, mii = -1;
        for (int i = 1; i <= m; ++i) if (!was[i] && D[i + n] < mi) {
            mi = D[i + n];
            mii = i + n;
        }
        if (mii == -1) continue;
        int x = mii;
        was[x - n] = true;
        ++ans;
        while (x != X) {
            flow[ P[x] ][x]++;
            flow[x][ P[x] ]--;
            ans2 += cost[ P[x] ][x];
            x = P[x];
        }
    }
    cout << ans << " " << ans2 << endl;
    for (int i = 1; i <= n; ++i) {
        int o = 0;
        for (int j = 0; j < g[i].size(); ++j) if (flow[i][g[i][j]] > 0)
            o = g[i][j] - n;
        cout << o << " ";
    }
    cout << endl;
    
    return 0;
}
