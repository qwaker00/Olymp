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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 11111
#define M 222222

bool mark[N][33];
int kk, xx[N], yy[M], pp[M], ord[N], ordn = 0;
bool was[N];
int n, m, k, vmark[N], x, y;
char task[M];
bool superv[N];
vector<int> g[N];

void dfs(int x) {
    was[x] = true;
    for (int i = xx[x]; i; i = pp[i])
        if ( (i & 1) == 1 && !was[yy[i]])
            dfs(yy[i]);
    ord[ordn++] = x;
}
void dfs2(int x, int markx, int markb) {
    if (!mark[x][markb]) {
        superv[markx] = false;
    }
    vmark[x] = markx;
    was[x] = true;
    for (int i = xx[x]; i; i = pp[i])
        if ( (i & 1) == 0 && !was[yy[i]])
            dfs2(yy[i], markx, markb);
}
void dfs3(int x) {
    was[x] = true;
//    cerr << x << endl;
    for (int i = 0; i < g[x].size(); i++) {
        if (!was[g[x][i]]) {
            dfs3(g[x][i]);
        }
//        cerr << "\t" << g[x][i] << endl;
        superv[x] &= superv[ g[x][i] ];
    }
    ord[ordn++] = x;
}

int main() {
    freopen("kripke.in", "r", stdin);
    freopen("kripke.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        int c;
        char ch;

        scanf("%d", &c);
        for (int j = 0; j < c; ++j) {
            scanf(" %c", &ch);
            mark[i][ch - 'a'] = true;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d%d\n", &x, &y);
        yy[++kk] = y; pp[kk] = xx[x]; xx[x] = kk;
        yy[++kk] = x; pp[kk] = xx[y]; xx[y] = kk;
    }

    int marka = -1, markb = -1;
    cin >> task;
    for (int j = 0; task[j]; ++j) if (task[j] >= 'a') {
        if (marka == -1) marka = task[j] - 'a';else
                         markb = task[j] - 'a';
    }

    memset(was, 0, sizeof(was));
    for (int i = 1; i <= n; i++) if (!was[i]) dfs(i);

    memset(was, 0, sizeof(was));
    memset(superv, 0, sizeof(superv));
    int it = 0;
    for (int i = 1; i <= n; i++) if (!was[ ord[ordn - i] ]) {
        superv[++it] = true;
        dfs2(ord[ordn - i], it, markb);
    }

//    for (int i = 1; i <= n; i++) cerr << vmark[i] << " ";
//    cerr << endl;

    for (int i = 1; i <= n; i++) 
        for (int j = xx[i]; j; j = pp[j])
            if ( (j & 1) == 1 ) {
                if (vmark[i] != vmark[ yy[j] ]) {
                    g[vmark[i]].push_back(vmark[ yy[j] ]);
//                    cerr << vmark[i] << " " << vmark[yy[j]] << endl;
                }
            }
    ordn = 0;
    memset(was, 0, sizeof(was));
    for (int i = 1; i <= it; i++) if (!was[i]) dfs3(i);

    memset(was, 0, sizeof(was));
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++) if (superv[vmark[i]]) {
        q.push(i);
        was[i] = true;
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        ans.push_back(x);

        for (int i = xx[x]; i; i = pp[i])
            if ( (i&1) == 0 && !was[yy[i]] && mark[yy[i]][marka] == true) {
                q.push(yy[i]);
                was[yy[i]] = true;
            }
    }
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
    
    return 0;
}
