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

const int N = 333333;

vector< int > g[N]; 
int n;
pair<int, int> best1[N], best2[N];
int ansrev[N], p[N], v[N], out[N];

void getx(int& x) {
    char c;
    while ((c = getchar()) < '0');
    x = c - 48;
    while ((c = getchar()) >= '0') x = x * 10 + c - 48;    
}


pair<int, int> dfs1(int x) {
    best1[x] = best2[x] = make_pair(-1, x);
    for (int i = 0; i < (int)g[x].size(); ++i)
        if (g[x][i] != p[x]) {
            p[ g[x][i] ] = x;
            pair<int, int> t = dfs1(g[x][i]);
            if (t > best1[x]) {
                best2[x] = best1[x];
                best1[x] = t;
            } else if (t > best2[x]) {
                best2[x] = t;
            }
        }
    ++best1[x].first;
    ++best2[x].first;
    return make_pair(best1[x].first, x);
}

void dfs2(int x) {
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (g[x][i] != p[x]) {
            ansrev[ g[x][i] ] = max(ansrev[x], best1[x].second == g[x][i] ? best2[x].first : best1[x].first) + 1;
            dfs2(g[x][i]);
        }
    }    
}

int main() {
    freopen("amoeba.in", "r", stdin);
    freopen("amoeba.out", "w", stdout);
    
    int a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i < n; ++i) {
        int x, y;
        getx(x);
        getx(y);
//        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs1(1);
    dfs2(1);

    for (int i = 1; i <= n; ++i) {
        int vn = 0;

        v[vn++] = ansrev[i];
        for (int j = 0; j < (int)g[i].size(); ++j) {
            if (g[i][j] != p[i]) {
                v[vn++] = best1[ g[i][j] ].first + 1;
            }
        }

        sort(v, v + vn, greater<int>());
        for (int j = 0; j < vn; ++j) {
            out[ v[j] ] = max(out[ v[j] ], j + 1);
        }
    }

    for (int i = n - 1; i > 0; --i) if (out[i + 1] > out[i]) out[i] = out[i + 1];
    for (int i = a; i <= b; ++i) printf("%d\n", out[i]);

    cerr << clock() << endl;
    
    return 0;
}
