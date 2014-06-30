#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <queue>
using namespace std;

typedef unsigned long long ULL;

const int N = 25555;
int st[N];
int D[N];
int was[N];
int ff[111111], ffideal[111111];

vector<pair<int, int> > g[N];
vector<int> f[N];
int W[N], WT;

bool dfs(int x) {
    if (x == 1) return true;
    if (W[x] == WT) return false;
    W[x] = WT;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (ff[f[x][i]] && dfs(g[x][i].first)) {
            ff[f[x][i]] = 0;
            ff[f[x][i] ^ 1] = 1;
            return true;
        }
    }
    return false;
}

int main() {
    //freopen(".in", "r", stdin);
    ios::sync_with_stdio(false);

    int n, m, c, en = 0;
    cin >> n >> m >> c;
    for (int i= 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
        f[x].push_back(en++);
        f[y].push_back(en++);
    }
    for (int i = 0; i < c; ++i) {
        cin >> st[i];
    }

    memset(D, 63, sizeof(D));
    D[1] = 0;
    priority_queue< pair<int, int> > q;
    q.push(make_pair(-D[1], 1));
    while (!q.empty()) {
        pair<int, int> t = q.top(); q.pop();
        int d = -t.first;
        int x = t.second;
        if (D[x] != d) continue;
        for (int i = 0; i < (int)g[x].size(); ++i) {
            int y = g[x][i].first;
            if (D[y] > D[x] + g[x][i].second) {
                D[y] = D[x] + g[x][i].second;
                q.push(make_pair(-D[y], y));
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j  = 0; j < (int)g[i].size(); ++j)
            if (D[i] == g[i][j].second + D[g[i][j].first]) {
                ffideal[f[i][j]] = 1;
            }

    int ans = 0;
    for (int i = 0; i < c; ++i) if (!was[i]) {
        memcpy(ff, ffideal, sizeof(ff[0]) * (m * 2));
        for (int j = i; j < c; ++j) if (D[ st[i] ] == D[ st[j] ]) {
            was[j] = 1;
            ++WT;
            ans += dfs(st[j]);
        }
    }
    cout << ans << endl;


    return 0;
}
