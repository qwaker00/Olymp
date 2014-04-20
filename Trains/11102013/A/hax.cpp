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
#include <unordered_map>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 11111

struct Tp {
    int score, mask;
} a[N];
int n, k, m;
unordered_map<int, vector<int> > v[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d%d", &a[i].score, &t);
        for (int j = 0; j < t; ++j) {
            int x;
            scanf("%d", &x);
            a[i].mask |= (1 << (x - 1));
        }
        for (int j = 0; j < (1 << k); ++j) v[j][j & a[i].mask].push_back(a[i].score);
    }
    for (int i = 0; i < (1 << k); ++i)
        for (unordered_map<int, vector<int> >::iterator j = v[i].begin(); j != v[i].end(); ++j)
            sort(j->second.begin(), j->second.end(), greater<int>());

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, t, msk1 = 0, msk2 = 0;
        scanf("%d%d", &x, &t);
        for (int j = 0; j < t; ++j) {
            int y;
            scanf("%d", &y);
            msk1 |= (1 << (y - 1));
            msk2 |= a[x].mask & (1 << (y - 1));
        }
        vector<int>& vv = v[msk1][msk2];
        printf("%d\n", (int)(lower_bound(vv.begin(), vv.end(), a[x].score, greater<int>()) - vv.begin()) + 1);
    }
    
    return 0;
}
