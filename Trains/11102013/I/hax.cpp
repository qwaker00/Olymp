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

int n, m;
char s[25][25];

int S, T, In[25][25], Out[25][25];
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int fl[1111][1111], D[1111], start[1111];
vector<int> g[1111];

inline void Add(int x, int y) {
    fl[x][y] = 1;
    fl[y][x] = 0;
    g[x].push_back(y);
    g[y].push_back(x);
}

bool bfs(int x) {
    queue<int> q;
    memset(D, 63, sizeof(D));
    D[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < g[x].size(); ++i) {
            if (fl[x][g[x][i]] > 0 && D[g[x][i]] > D[x] + 1) {
                D[g[x][i]] = D[x] + 1;
                q.push(g[x][i]);
            }
        }
    }
    return D[T] < 1e9;
}

int dfs(int x, int maxfl = 2e9) {
    if (x == T) return maxfl;

    int totfl = 0;
    for (int& i = start[x]; i < g[x].size(); ++i) {
        int y = g[x][i];
        if (D[x] + 1 != D[y] || fl[x][y] <= 0) continue;

        int f = dfs(y, min(maxfl - totfl, fl[x][y]));
        if (f) {
            fl[x][y] -= f;
            fl[y][x] += f;
            totfl += f;
            if (totfl == maxfl) break;
        }
    }

    return totfl;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
    }

    int cnt = 0;
    S = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            In[i][j] = ++cnt;
            Out[i][j] = ++cnt;
        }
    T = ++cnt;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; j++) {
            Add(In[i][j], Out[i][j]);
            if (s[i][j] == 'W') {
                Add(S, In[i][j]);
            } else
            if (s[i][j] == 'N') {
                Add(Out[i][j], T);
            } else {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && y >= 0 && x < n && y < m) {
                        if (s[x][y] == 'N') Add(Out[i][j], In[x][y]);
                        if (s[x][y] == 'W') Add(Out[x][y], In[i][j]);
                    }
                }
            }
        }
    }

    int ans = 0;
    while (bfs(0)) {        
        memset(start, 0, sizeof(start));
        ans += dfs(0);
    }
    cout << ans << endl;
    
    return 0;
}
