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

#define N 777

int n, m;
int pr[N];
int was[N][N];
int conn;
struct Tp {
    int x, y;
} a[N];

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    for (int i= 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    for (int i = 1; i <= n; ++i) pr[i] = i;
    conn = 0;

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        was[x][y] = was[y][x] = 1;
        if (fs(x) != fs(y)){
            pr[fs(x)] = fs(y);
            ++conn;
        }
    }

    vector< pair<int, pair<int, int> > > e;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!was[i][j]) {
                e.push_back(make_pair(sqr(a[i].x - a[j].x) + sqr(a[i].y - a[j].y), make_pair(i, j)));
            }
        }
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < e.size() && conn < n - 1; ++i) {
        int x = e[i].second.first;
        int y = e[i].second.second;
        if (fs(x) != fs(y)) {
            pr[fs(x)] = fs(y);
            ++conn;
            printf("%d %d\n", x + 1, y + 1);
        }
    }
    
    return 0;
}
