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

vector<int> g[111111];
int f[111111][2];

void dfs(int x, int pr = -1) {
    f[x][0] = 0;
    f[x][1] = 0;
    int mi = 1e9;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (g[x][i] != pr) {
            dfs(g[x][i], x);
            f[x][0] += f[ g[x][i] ][1];
            if (mi > f[ g[x][i] ][1] - f[ g[x][i] ][0]) {
                mi = f[ g[x][i] ][1] - f[ g[x][i] ][0];
            }
        }
    }
    f[x][1] = max(f[x][0], f[x][0] - mi + 1);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int N;
    cin >> N;
    --N;
    while (N--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    cout << f[1][1] << endl;
    
    return 0;
}
