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

struct Tp {
    int c;
    int l, r;

    Tp(int c = 0, int l = 0, int r = 0): c(c), l(l), r(r) {};
};

struct Te {
    int x, t;

    bool operator<(const Te& b) const {
        return x < b.x || (x == b.x && t > b.t);
    }
} e[111111];
int en;

vector<int> xx;
vector< Tp > h, v;
int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            v.push_back(Tp(x1, y1, y2));
            xx.push_back(x1);
        } else {
            if (x1 > x2) swap(x1, x2);
            h.push_back(Tp(y1, x1, x2));
        }
    }
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());

    int ans = 0;

    for (int i = 0; i < xx.size(); ++i)
    for (int j = i + 1; j < xx.size(); ++j) {
        int L = xx[i];
        int R = xx[j];

        en = 0;
        for (int k = 0; k < h.size(); ++k) {
            if (h[k].l <= L && h[k].r >= R) {
                e[en].x = h[k].c;
                e[en].t = 0;
                ++en;
            }
        }
        for (int k = 0; k < v.size(); ++k) {
            if (v[k].c == L || v[k].c == R) {
                e[en].x = v[k].l;
                e[en].t = +1;
                ++en;

                e[en].x = v[k].r;
                e[en].t = -1;
                ++en;
            }
        }
        sort(e, e + en);

        int cover = 0, cnt = 0;
        for (int k = 0; k < en; ++k) {
            if (e[k].t == +1) {
                ++cover;
            } else
            if (e[k].t == -1) {
                --cover;
                cnt = 0;
            } else {
                if (cover == 2) {
                    ans += cnt;
                    ++cnt;
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
