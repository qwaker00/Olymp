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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 222222;

vector<int> g[N];
int removed[N], n;
LL value[N];

void dfsadd(int x, LL val) {
    if (removed[x]) return;
    value[x] += val;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        dfsadd(g[x][i], val);
    }
}

void dfsremove(int x) {
    if (removed[x]) return;
    removed[x] = 1;
    for (int i = 0; i < (int)g[x].size(); ++i) {
        dfsremove(g[x][i]);
    }
}

LL dfssum(int x) {
    if (removed[x]) return 0;
    LL sum = value[x];
    for (int i = 0; i < (int)g[x].size(); ++i) {
        sum += dfssum(g[x][i]);
    }
    return sum;
}

inline void create(int key, LL val) {
    int nkey = n++;
    g[key].push_back(nkey);
    value[nkey] = val;
}

inline void add(int key, LL val) {
    dfsadd(key, val);
}

inline void clear(int key) {
    dfsremove(key);
}

inline LL sum(int key) {
    return dfssum(key);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        value[i] = x;
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }

    LL SPECIAL = 0;
    int q;
    scanf("%d", &q);
    while (q--) {
        LL key;
        int t, value;
        scanf("%d", &t);        
        switch (t) {
            case 1:
                scanf("%lld%d", &key, &value);
                create(key + SPECIAL, value);
            break;

            case 2:
                scanf("%lld%d", &key, &value);
                add(key + SPECIAL, value);
            break;

            case 3:
                scanf("%lld", &key);
                clear(key + SPECIAL);
            break;

            case 4:
                scanf("%lld", &key);
                SPECIAL = sum(key + SPECIAL);
                printf("%lld\n", SPECIAL);
                SPECIAL = 0;
            break;
        }
    }
    cerr << clock() << endl;

    return 0;
}
