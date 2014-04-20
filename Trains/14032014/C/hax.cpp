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

#define EPS 1e-10

const int N = 22222;

int n, m, q;
vector<int> g[N];
struct Te {
    int x, y, z;
} e[N];
double cost[N], D[N];
int spec[N], start, finish, was[N];

double shortest() {
    for (int i = 0; i < n; ++i) {
        D[i] = 1e18;
        was[i] = 0;
    }
    D[0] = 0;
    for (int it = 1; it < n; ++it) {
        int mi = -1;
        for (int i = 0; i < n; ++i)
            if (!was[i] && (mi == -1 || D[mi] > D[i]))
                mi = i;
        was[mi] = 1;
        for (int i = 0; i < (int)g[mi].size(); ++i) {
            int y = e[ g[mi][i] ].y == mi ? e[ g[mi][i] ].x : e[ g[mi][i] ].y;
            double d = cost[ g[mi][i] ] + D[mi];
            if (D[y] > d) D[y] = d;
        }            
    } 
    return D[n - 1];
}

int main() {
    freopen("lateagain.in", "r", stdin);
    freopen("lateagain.out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
        --e[i].x;
        --e[i].y;
        g[e[i].x].push_back(i);
        g[e[i].y].push_back(i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        spec[x - 1] = 1;
    }

    double left = 0;
    double right = 10000;
    while (right - left > 1e-10) {
        double center = (left + right) / 2, pathl = 0;
        for (int i = 0; i < m; ++i)
            if (spec[i]) {
                cost[i] = max(1., e[i].z - center);
                pathl += cost[i];
            } else
                cost[i] = e[i].z + center;
        if (fabsl(shortest() - pathl) < EPS) {
            right = center;
        } else {
            left = center;
        }
    }
    double center = (left + right) / 2;
    printf("%.10lf\n", center);
    for (int i = 0; i < m; ++i)
        if (spec[i]) {
            printf("%.10lf ", max(1., e[i].z - center));
        } else
            printf("%.10lf ", e[i].z + center);
    puts("");
    return 0;
}
