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

pair<int, int> a[1111], b[1111];

inline bool InFixed(pair<int, int> a, pair<int, int> b) {
    return a.first >= b.first && a.second <= b.second;
}

inline bool In(pair<int, int> a, pair<int, int> b, int n) {
    if (a.first > a.second) a.second += n;
    if (b.first > b.second) b.second += n;
    return InFixed(a, b) || 
           InFixed(make_pair(a.first + n, a.second + n), b);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, p;
        scanf("%d%d%d", &n, &k, &p);
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &a[i].first, &a[i].second);
        }
        for (int i = 0; i < p; ++i) {
            scanf("%d%d", &b[i].first, &b[i].second);
        }

        bool good = true;
        for (int i = 0; i < k; ++i) {
            bool g = false;
            for (int j = 0; j < p; ++j) 
                if (In(a[i], b[j], n)) {
                    g = true;
                    break;
                }
            if (!g) {
                good = false;
                break;
            }
        }
        puts(good ? "Yes" : "No");
    }

    return 0;
}
