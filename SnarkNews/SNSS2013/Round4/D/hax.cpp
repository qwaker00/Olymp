#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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


struct Tnum {
    int x1;
    int x2;

    #define M 1000000007

    Tnum() : x1(0), x2(0) {}
    Tnum(LL y1, LL y2) {
        x1 = y1 % M;
        x2 = y2 & 1;
    }
    Tnum operator+(const Tnum& x) {
        return Tnum(x.x1 + x1, x.x2 + x2);
    }
    Tnum operator*(LL x) {
        return Tnum(x * x1, x * x2);
    }
} res[111111];

int pr[111111], w[111111];
vector<int> g[111111];
int n;

void dfs(int x) {
    if (g[x].size()) {
        for (int i = 0; i < g[x].size(); ++i) {
            dfs(g[x][i]);
            res[x] = res[g[x][i]] * w[g[x][i]] + res[x];
        }
    } else {
        res[x] = Tnum(1, 1);
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d", &n);    
    for (int i = 1; i < n; ++i) {
        scanf("%d", &pr[i]);
        g[pr[i]].push_back(i);
    }
    for (int i = 1; i < n; ++i) {
        scanf("%d", &w[i]);
    }
    dfs(0);
    if (res[0].x2) {
        printf("%d\n", res[0].x1);
    } else
        puts("Pass");
    
    return 0;
}
