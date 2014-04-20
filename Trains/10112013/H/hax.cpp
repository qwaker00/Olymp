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

vector<int> g[422222];
int mark[422222], del[422222];
vector<int> ans[2];
vector< pair<int, int> > v;

int go(int x, int p) {
    if (g[x].size()  == 4) return x;
    if (g[x][0] == p)
        return go(g[x][1], x);else
        return go(g[x][0], x);
}

int go2(int x, int p, int& cnt, int* lst) {
    ++cnt;
    if (g[x].size()  == 4) {
        *lst = p;
        return x;
    }
    if (g[x][0] == p)
        return go2(g[x][1], x, cnt, lst);else
        return go2(g[x][0], x, cnt, lst);
}

void dfs(int x, int c) {
    if (del[x] || mark[x] != -1) return;

    mark[x] = c;
    ans[c].push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
        dfs(g[x][i], 1 - c);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    memset(mark, -1, sizeof(mark));

//    int ans = 0;
    for (int i = 1; i <= n; ++i) if (g[i].size() == 4) {
//        mark[i] = 0;
        for (int j = 1; j < g[i].size(); ++j) {
            if (go(g[i][j], i) == go(g[i][0], i)) {
                
                int x = i, lst1, lst2;
                if (j == 1) {
                    lst1 = g[i][2];
                    lst2 = g[i][3];
                } else
                if (j == 2) {
                    lst1 = g[i][1];
                    lst2 = g[i][3];
                } else {
                    lst1 = g[i][1];
                    lst2 = g[i][2];
                }

                do {
                    int cnt = 0;
                    int l1 = -1, l2 = -1, y;
                    for (int k = 0; k < 4; ++k)
                        if (g[x][k] != lst1 && g[x][k] != lst2)
                        {
                            y = go2(g[x][k], x, cnt, (l1 == -1) ? &l1 : &l2);
                        }
                    v.push_back(make_pair(cnt, y));
                    lst1 = l1;
                    lst2 = l2;
                    x = y;
                } while (x != i);
                break;
            }
        }
        break;
    }
    
    int nn = v.size();
    for (int i = 0; i < nn; ++i) v.push_back(v[i]);
    int start = 0;
    for (int i = 0; i < nn; ++i) if (v[i].first % 2 == 0) {
        start = i;
        break;
    }
    int save = 0;
    for (int i = start; i < start + nn; ++i) {
        if (v[i].first % 2 == 1) {
            if (!save) {
                del[v[i].second] = 1;
                save = 1;
            } else
                save = 0;
        } else save = 0;
    }
    for (int i = 1; i <= n; ++i) if (mark[i] == -1 && !del[i]) dfs(i, 0);

//    cout << ans << endl;
    printf("%d", (int)ans[0].size());
    for (int i= 0; i < ans[0].size(); ++i) printf(" %d", ans[0][i]);
    puts("");

    printf("%d", (int)ans[1].size());
    for (int i= 0; i < ans[1].size(); ++i) printf(" %d", ans[1][i]);
    puts("");
    
    return 0;
}
