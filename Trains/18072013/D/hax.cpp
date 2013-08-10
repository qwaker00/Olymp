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

#pragma comment(linker, "/STACK:64777216")

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 2222;
const int M = 333333;
int level[N];
LL f[N];
LL ans[M];
int target;

vector< pair<int, pair<int, int> > > g[N];
vector<int> order[N];
                            
int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x); --x;
        level[i] = x;
        order[x].push_back(i); 
    }

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        --a; --b;
        if (level[a] + 1 == level[b]) g[a].push_back(make_pair(i, make_pair(b, c)));
    }
    int source = order[0][0];
    target = order[l - 1][0];


    f[source] = LL(n) * LL(n) * LL(1e7);
    for (int level = 0; level < l; ++level) {
        for (int q = 0; q < order[level].size(); ++q) {
            int x = order[level][q];

            for (int i = 0; i < g[x].size(); ++i) {
                int y = g[x][i].second.first;
                LL cost = g[x][i].second.second;
                int num = g[x][i].first;

                int got = min(cost, f[x]);
                ans[num] = got;
                f[y] += got;
            }
        }
    }

    memset(f, 0, sizeof(f));
    f[target] = LL(n) * LL(n) * LL(1e7);
    for (int level = l - 2; level >= 0; --level) {
        for (int q = 0; q < order[level].size(); ++q) {
            int x = order[level][q];

            for (int i = 0; i < g[x].size(); ++i) {
                int y = g[x][i].second.first;
                int num = g[x][i].first;

                int got = min(ans[num], f[y]);
                ans[num] = got;
                f[x] += got;
                f[y] -= got;
            }
        }
    }
    
    
    for (int i = 0; i < m; ++i) {
        printf("%d\n", (int) ans[i]);
    }

    return 0;
}

