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

#define N 111
#define NN N*N
#define M 2111111

int n1, m1, n2, m2, c;
int go1[N][N], go2[N][N], go3[NN][N];
int v[N][N];
int yy[M], pp[M], xx[NN], kk = 0;
int was[NN], was2[NN];

inline void add(int x, int y) {
    yy[++kk] = y, pp[kk] = xx[x], xx[x] = kk;
}

void bfs(int x) {
    queue<int> q;
    memset(was, 0, sizeof(was));
    was[x] = 1;
    q.push(x);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = xx[x]; i; i = pp[i]) {
            int y = yy[i];
            if (was[y]) continue;
            was[y] = 1;
            q.push(y);
        }
    }
}

int main() {
    freopen("mazes.in", "r", stdin);
    freopen("mazes.out", "w", stdout);
    
    scanf("%d", &c);

    scanf("%d%d", &n1, &m1);
    for (int i = 0; i < m1 ; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        go1[x][c] = y;
    }
    scanf("%d%d", &n2, &m2);
    for (int i = 0; i < m2 ; ++i) {
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        go2[x][c] = y;
    }

    int vn = 0;
    for (int i = 1; i <= n1; ++i)
        for (int j = 1; j <= n2; ++j)
            v[i][j] = ++vn;
    for (int i = 1; i <= n1; ++i)
        for (int j = 1; j <= n2; ++j) {
            for (int k = 1; k <= c; ++k) {
                if (!go1[i][k] || !go2[j][k]) continue;
                go3[v[i][j]][k] = v[go1[i][k]][go2[j][k]];
                add(v[go1[i][k]][go2[j][k]], v[i][j]);
            }
        }
    bfs(v[n1][n2]);
    if (!was[v[1][1]]) {
        puts("no common solution");
        return 0;
    }
    vector<int> ans;
    memset(was2, 0, sizeof(was2));
    int x = v[1][1];
    while (x != v[n1][n2]) {
        if (was2[x]) {
            puts("no smallest solution");
            return 0;
        }
        was2[x] = 1;
        for (int i = 1; i <= c; ++i) {
            if (was[go3[x][i]]) {
                x = go3[x][i];
                ans.push_back(i);
                break;
            }
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    puts("");

    return 0;
}
