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

map<int, int> add[111111];

inline int get(int x, int y) {
    map<int, int>::iterator i = add[x].find(y);
    if (i == add[x].end()) return 0;
    return i->second;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    while (p--) {
        int x, y;
        scanf("%d%d", &x, &y);
        ++add[x][y];
    }
    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (map<int, int>::iterator j = add[i].begin(); j != add[i].end(); ++j) {
            if (j->first == m) break;
            if (j->first + j->second > j->first + 1 + get(i, j->first + 1)) {
                ok = false;
                break;
            }
        }
        if (!ok)
            puts("-1");else
            printf("%d\n", m + get(i, m) - 1 - get(i, 1));
    }
    
    return 0;
}
