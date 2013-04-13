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
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, x;
vector<int> g[222];
int pr[222], was[222], IT = 0, a[222][222];

bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;
    for (size_t i = 0; i < g[x].size(); ++i)
        if (pr[ g[x][i] ] == -1 || kuhn(pr[g[x][i]])) {
            pr[ g[x][i] ] = x;
            return true;
        }
    return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (a[i][k] && a[k][j])
                        a[i][j] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] == 1) {
                    g[i].push_back(j);
//                    cerr << i << " " << j << endl;
                }
            }
        }

        memset(pr, -1, sizeof(pr));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ++IT;
            if (kuhn(i)) ++ans;
        }
        cout << n - ans << endl;
        for (int i = 1; i <= n; ++i) g[i].clear();
    }
     
    
    return 0;
}
