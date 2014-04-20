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
#include <unordered_set>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define P1 37
#define P2 191
#define P3 6527

namespace std {
    template<>
    struct hash< pair<ULL, pair<ULL, ULL> > > {
        size_t operator()(const pair<ULL, pair<ULL, ULL> >& p) const {
            return p.first ^ p.second.first ^ p.second.second ^ (p.first >> 32) ^ (p.second.first >> 32) ^ (p.second.second);
        }
    };
}

ULL p1[224], p2[224], p3[224];
int T, n, m;
int a[224], h[224], prv[112], v[224];
pair<ULL, pair<ULL, ULL> > hs[224];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    p1[0] = 1;
    for (int i = 1; i <= 200; ++i) p1[i] = p1[i - 1] * P1;
    p2[0] = 1;
    for (int i = 1; i <= 200; ++i) p2[i] = p2[i - 1] * P2;
    p3[0] = 1;
    for (int i = 1; i <= 200; ++i) p3[i] = p3[i - 1] * P3;

    scanf("%d", &T);
    while (T--) {
        unordered_set< pair<ULL, pair<ULL, ULL> > > was;
        int ans = 0;

        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a[j]); 
                h[j] = a[j];
            }

            sort(h, h + m);
            int hn = unique(h, h + m) - h;

            memset(prv, -1, sizeof(prv));
            for (int j = 0; j < m; ++j) prv[a[j] = lower_bound(h, h + hn, a[j]) - h] = j;
            for (int j = 0; j < m; ++j) {    
                v[j] = v[j + m] = j + m - prv[a[j]];
                prv[a[j]] = j + m;
            }

            bool bad = 0;
            for (int j = 0; j < m + m; ++j) {
                hs[j+1].first = hs[j].first * P1 + v[j];
                hs[j+1].second.first = hs[j].second.first * P2 + v[j];
                hs[j+1].second.second = hs[j].second.second * P3 + v[j];
                if (j >= m) {
                    hs[j+1].first -= v[j - m] * p1[m];
                    hs[j+1].second.first -= v[j - m] * p2[m];
                    hs[j+1].second.second -= v[j - m] * p3[m];
                    if (was.count(hs[j+1])) {
                        bad = 1;
                        break;
                    }
                }
            }
            for (int j = m; j < m + m; ++j) was.insert(hs[j]);
            ans += !bad;
        }
        cout << ans << endl;
    }
    
    return 0;
}
