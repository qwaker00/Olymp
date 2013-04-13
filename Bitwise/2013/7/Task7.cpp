#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

const int N = 1111;
int nxt[N], deg[N], prev[N];
bool was[N], used[N];
vector<int> gt[N];
vector<int> g[N];

ll f[N][2], F[N][2][2];

void dfs(int x) {
    was[x] = true;
    for (int i = 0; i < gt[x].size(); ++i)
        if (!used[ gt[x][i] ]) dfs(gt[x][i]);

    f[x][0] = 1;
    f[x][1] = 1;
    for (int i = 0; i < gt[x].size(); ++i) 
        if (!used[ gt[x][i] ]) {
            f[x][0] = (f[x][0] * (f[ gt[x][i] ][0] + f[ gt[x][i] ][1])) % MOD;
            f[x][1] = (f[x][1] * f[ gt[x][i] ][0]) % MOD;
        }
}

int calc(int x) {
    vector<int> a;

    bool gotCycle = true;
    while (!was[x]) {
        was[x] = true;
        if (nxt[x] == -1) {
            gotCycle = false;
            break;
        }
        prev[ nxt[x] ] = x; 
        x = nxt[x];
    }

    if (gotCycle) {
        int firstVertex = x;
        while (prev[x] != firstVertex) {
            a.push_back(x);
            used[x] = true;
            x = prev[x];
        }
        a.push_back(x);
        used[x] = true;

        for (int i = 0; i < a.size(); ++i) { 
            dfs(a[i]);
        }

        F[0][0][0] = f[ a[0] ][0];
        F[0][1][1] = f[ a[0] ][1];
        for (int i = 1; i < a.size(); ++i)
            for (int j = 0; j < 2; ++j) {
                F[i][j][0] = ((F[i - 1][j][0] + F[i - 1][j][1]) * f[ a[i] ][0]) % MOD;
                F[i][j][1] = ((F[i - 1][j][0]) * f[ a[i] ][1]) % MOD;
            }
       
        int len = a.size();
        return (F[len - 1][0][0] + F[len - 1][0][1] + F[len - 1][1][0]) % MOD;
    } else {
        dfs(x);
        return (f[x][0] + f[x][1]) % MOD;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);

        memset(nxt, -1, sizeof(nxt));
        memset(was, 0, sizeof(was));
        memset(used, 0, sizeof(used));
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            gt[i].clear();
        }

        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            
            g[a].push_back(b);
            gt[b].push_back(a);

            nxt[a] = b;
        }

        
        ll ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (!was[i]) {
                ans = (ans * ll(calc(i))) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

