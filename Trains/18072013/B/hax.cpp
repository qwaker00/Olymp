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


vector<int> g[444];
int v[444], n, pr[444], IT, was[444], ans[444];

bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;

    for (int i= 0; i < g[x].size(); ++i) {
        if (pr[g[x][i]] == -1 || kuhn(pr[g[x][i]])) {
            pr[g[x][i]] = x;
            return true;
        }
    }

    return false;
}

int main() {
    freopen("beloved.in", "r", stdin);
    freopen("beloved.out", "w", stdout);

    vector< pair<int, int> > vv;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        vv.push_back(make_pair(-v[i], i));
    }

    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j)  {
            int x;
            scanf("%d", &x);
            g[i].push_back(x - 1);
        }
    }

    memset(pr, -1, sizeof(pr));
    IT = 0;

    sort(vv.begin(), vv.end());
    for (int i = 0; i < n; ++i) {
        ++IT;
        kuhn(vv[i].second);
    }
    for (int i = 0; i < n; ++i) if (pr[i] != -1) ans[pr[i]] = i + 1;

    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    
    return 0;
}
