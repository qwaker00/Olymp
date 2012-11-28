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

using namespace std;

const int N = 1111;
int p[N], x[N], y[N], d[N][N], D[N], from[N], f[N];

double W;
double ans;

bool u[N];
int n;

vector<int> g[N];

inline int sqr(int x) {
    return x * x;
}

void cdfs(int x) {
    f[x] = p[x];

    for (size_t i = 0; i < g[x].size(); ++i) {
        cdfs(g[x][i]);
        f[x] = max(f[x], f[ g[x][i] ]);
    }
}

void dfs(int x, int umax) {
    umax = max(umax, p[x]);

    int mx1 = -1, mx2 = -1;
    for (size_t i = 0; i < g[x].size(); ++i) {
        mx2 = max(mx2, f[ g[x][i] ]);
        if (mx1 < mx2) {
            swap(mx2, mx1);
        }
    }
    
    for (size_t i = 0; i < g[x].size(); ++i) {
        int omax = mx1;
        if (f[ g[x][i] ] == omax) {
            omax = mx2;
        }        

        dfs(g[x][i], max(omax, umax));
        
        double na = f[ g[x][i] ] + max(omax, umax);
        double nb = W - sqrt(double(d[x][ g[x][i] ]));

        if (ans < na / nb) {
            ans = na / nb;
        }
    }
}

double getit(double x) {
    return round(x * 100.) / 100.;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T;

    scanf("%d", &T);
    for (int _test = 1; _test <= T; ++_test) {
        scanf("%d", &n);    
        
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", x + i, y + i, p + i);
            g[i].clear();
        }

        for (int i = 0; i < n; ++i) {
            d[i][i] = 0;
            for (int j = 0; j < n; ++j) {
                d[i][j] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
                d[j][i] = d[i][j];
            }                             
        }

        memcpy(D, d[0], sizeof(D));
        memset(u, 0, sizeof(u));
        memset(from, 0, sizeof(from));
        u[0] = 1;
        W = 0;
        ans = -1;

        int add = 0;
        while (++add < n) {
            int cool = -1;
            for (int i = 0; i < n; ++i)
                if (!u[i] && (cool == -1 || D[cool] > D[i])) {
                    cool = i;
                }
            g[ from[cool] ].push_back(cool);
            cerr << from[cool] << " " << cool << endl;
            u[cool] = 1;
            W += sqrt(double(D[cool]));
            

            for (int i = 0; i < n; ++i)
                if (D[i] > d[cool][i]) {
                    D[i] = d[cool][i];
                    from[i] = cool;
                }
            
        }

        cdfs(0);
        dfs(0, -1);

        cout.precision(2);
        cout << fixed;
        cout << getit(ans) << endl;    
    }
    
    return 0;
}
