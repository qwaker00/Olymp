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

#define N 111111

ULL w[N], all = 0, ans = 0, G = 1;
int n, a[N];
vector<int> g[N];

#define MAX ((ULL)(1e13) + 1)

ULL gcd(ULL a, ULL b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int dfs(int x, ULL c, int pr = -1) {
    if (c > MAX) {
        cout << all << endl;
        exit(0);
    }

    int leaf = 1;
    for (size_t i = 0; i < g[x].size(); ++i) {
        if (g[x][i] == pr) continue;

        dfs(g[x][i], c * (g[x].size() - (pr != -1)), x);
        leaf = 0;
    }
    if (leaf) {
        if (LD(c) * a[x] < ans + 10)
            ans = min(ans, c * a[x]);
        ULL g = c / gcd(c, G);
        if (LD(G) * g < ans + 10)
            G *= g;
        else {
            cout << all << endl;
            exit(0);            
        }
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        all += a[i];
    }
    ans = all;
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);

    ans -= ans % G;
    cout << all - ans << endl;

    return 0;
}
