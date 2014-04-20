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

int D[N];
vector<int> g[N];

void farest(int x, int& ans) {
    if (D[x] > D[ans]) ans = x;
    for (int i = 0, y; i < g[x].size(); ++i) {
        if (D[y = g[x][i]] != -1) continue;
        D[y] = D[x] + 1;
        farest(y, ans);
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        int x, y;

        memset(D, -1, sizeof(D));
        D[1] = 0;
        x = 1;
        farest(1, x);

        memset(D, -1, sizeof(D));
        D[x] = 0;
        y = x;
        farest(x, y);

        cout << (D[y] + 1) / 2 << endl;
    }
    
    return 0;
}
