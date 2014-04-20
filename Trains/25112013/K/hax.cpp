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

#define N 1111

struct Tp {
    int x, y, i;

    bool operator<(const Tp& t) const {
        return x < t.x;
    }
} a[N];
vector<Tp> b[1111];
vector<int> g[1111];
int was[1111];
int e;
int n;

inline void add(int x, int y) {
    g[x].push_back(y);
    ++e;
}

bool dvudoll(int x, int mr) {
    if (was[x]) {
        if (mr != was[x]) return false;
        return true;
    }
    was[x] = mr;
    for (int i = 0; i < g[x].size(); ++i)
        if (!dvudoll(g[x][i], 3 - mr))
            return false;
    return true;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
        b[a[i].y].push_back(a[i]);
    }
    for (int i = 1; i <= 1000; ++i) sort(b[i].begin(), b[i].end());

    for (int i = 0; i < n; ++i) {
        for (int y2 = a[i].y - 1; y2 <= a[i].y + 1; ++y2) {
            int p = lower_bound(b[y2].begin(), b[y2].end(), a[i]) - b[y2].begin();
            if (p < b[y2].size()) {                
                if (b[y2][p].x == a[i].x) ++p;
                if (p < b[y2].size())
                    add(i, b[y2][p].i);
            }
            --p;
            if (p >= 0) {
                if (b[y2][p].x == a[i].x) --p;
                if (p >= 0)
                    add(i, b[y2][p].i);
            }
        }
    }
    if (e == 0) {
        puts("1");
    } else {        
        bool bad = false;
        for (int i = 0; i < n; ++i) if (!was[i] && !dvudoll(i, 1)) {
            bad = true;
            break;
        }
        if (!bad) {
            puts("2");
        } else {
            bool bad2 = false;
            for (int i = 1; i <= 1000 && !bad2; ++i) {
                if (b[i].size() > 1) {
                    for (int j = 1; j < b[i].size(); ++j) {
                        int p1 = lower_bound(b[i - 1].begin(), b[i - 1].end(), b[i][j - 1]) - b[i - 1].begin();
                        int p2 = lower_bound(b[i - 1].begin(), b[i - 1].end(), b[i][j]) - b[i - 1].begin() - 1;

                        if (p1 < p2) {
                            bad2 = true;
                            break;
                        }
                        p1 = lower_bound(b[i + 1].begin(), b[i + 1].end(), b[i][j - 1]) - b[i + 1].begin();
                        p2 = lower_bound(b[i + 1].begin(), b[i + 1].end(), b[i][j]) - b[i + 1].begin() - 1;
                        if (p1 < p2) {
                            bad2 = true;
                            break;
                        }                        
                    }
                }
            }
            if (bad2) {
                puts("4");
            } else
                puts("3");
        }
    }
    
    return 0;
}
