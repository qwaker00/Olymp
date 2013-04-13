#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <memory.h>
#include <cmath>
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


#define EPS 1e-10

LD SDist(LD x, LD y, LD z) {
    return x * x + y * y + z * z;
}

int n, R;
int x, y, z, vx, vy, vz;

vector< pair<int, int> > all;
vector< pair<int, int> > tt;
int ans[111111], m;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d", &n, &R);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        scanf("%d%d%d", &vx, &vy, &vz);

        LD left = 0;
        LD right = 1e9;
        for (int it = 0; it < 150; ++it) {
            LD c1 = left + (right - left) / 3;
            LD c2 = right - (right - left) / 3;
            if (SDist(x + vx * c1, y + vy * c1, z + vz * c1) < SDist(x + vx * c2, y + vy * c2, z + vz * c2)) {
                right = c2;
            } else
                left = c1;
        }
        LD mp = (left + right) / 2;
        if (SDist(x + vx * mp, y + vy * mp, z + vz * mp) - EPS > LD(R) * R) continue;

        left = 0;
        right = mp;
        for (int it = 0; it < 150; ++it) {
            LD c = (left + right) / 2;
            if (SDist(x + vx * c, y + vy * c, z + vz * c) <= LD(R) * R)
                right = c;
            else
                left = c;
        }
        for (int dk = max( (left + right) / 2 - 3, LD(0.)); dk <= (left + right) / 2 + 3; ++dk) {
            if (SDist(x + vx * dk, y + vy * dk, z + vz * dk) - EPS <= LD(R) * R) {
                all.push_back(make_pair(dk, -1));
                break;
            }
        }

        left = mp;
        right = 1e9;
        for (int it = 0; it < 150; ++it) {
            LD c = (left + right) / 2;
            if (SDist(x + vx * c, y + vy * c, z + vz * c) > LD(R) * R)
                right = c;
            else
                left = c;
        }
        for (int dk = (left + right) / 2 + 3; dk >= max(LD(0.), (left + right) / 2 - 3); --dk) {
            if (SDist(x + vx * dk, y + vy * dk, z + vz * dk) - EPS <= LD(R) * R) {
                all.push_back(make_pair(dk + 1, 1));
                break;
            }
        }
    }

    sort(all.begin(), all.end());

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        tt.push_back(make_pair(t, i));
    }
    sort(tt.begin(), tt.end());

    int bad = 0;
    for (int i = 0, j = 0; i < tt.size(); ++i) {
        while (j < all.size() && all[j].first <= tt[i].first) {
            bad -= all[j].second;
            ++j;
        }
        ans[tt[i].second] = bad;
    }
    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    
    return 0;
}
