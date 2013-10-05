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

inline bool Bit(int i, int x) {
    return i < 0 ? false : (x & (1 << i));
}

typedef vector< pair<pair<int, int>, int> > arr;
arr good1, good2;
arr::iterator j11[3333333], j21[11111111];
arr::iterator j12[3333333], j22[11111111];

int D[10][512][512];

LL Solve(int n, int m) {
    if (m == 1) {
        return 1;
    }
    memset(D, 0, sizeof(D));
    int start = ((1 << n) - 1);
    for (int i = 0; i < good1.size(); ++i) {
        if (good1[i].first.first == start) {
            D[0][good1[i].first.second][good1[i].second] = 1;
        }
    }
    for (int i = 1; i < m; ++i) {
        if (i & 1) {
            int t;
            for (int j = 0; j < good2.size(); ++j) {
                if (t = D[i - 1][good2[j].first.first][good2[j].first.second]) {
                    D[i][good2[j].first.second][good2[j].second] += t;
                }
            }
        } else {
            int t;
            for (int j = 0; j < good1.size(); ++j) {
                if (t = D[i - 1][good1[j].first.first][good1[j].first.second]) {
                    D[i][good1[j].first.second][good1[j].second];
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i < 512; ++i)
        ans += D[m - 1][i][0];
    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    for (int l1 = 0; l1 < (1 << 8); ++l1) {
        for (int l2 = 1; l2 < (1 << 9); ++l2) {
            for (int l3 = 0; l3 < (1 << 8); ++l3) {
                bool bad = false;
                for (int i = 0; i < 8; ++i)
                    if (Bit(l3, i) && !Bit(l2, i) && !Bit(l2, i + 1)) {
                        bad = true;
                        break;
                    }
                if (!bad)
                for (int i = 0; i < 9; ++i) if (Bit(i, l2)) {
                    if ( Bit(i, l1) && Bit(i - 1, l1) ||
                         Bit(i - 1, l1) && Bit(i - 1, l3) ||
                         Bit(i, l1) && Bit(i, l3) ||
                         Bit(i - 1, l1) && Bit(i + 1, l2) || 
                         Bit(i, l1) && Bit(i - 1, l2)
                       ) continue;
                    bad = true;
                    break;
                }
                if (!bad)
                    good1.push_back(make_pair(make_pair(l1, l2), l3));
            }
        }
    }
    for (int l1 = 0; l1 < (1 << 9); ++l1) {
        for (int l2 = 1; l2 < (1 << 8); ++l2) {
            for (int l3 = 0; l3 < (1 << 9); ++l3) {
                bool bad = false;
                for (int i = 0; i < 9; ++i)
                    if (Bit(l3, i) && !Bit(l2, i) && !Bit(l2, i - 1)) {
                        bad = true;
                        break;
                    }
                if (!bad)
                for (int i = 0; i < 8; ++i) if (Bit(i, l2)) {
                    if ( Bit(i, l1) && Bit(i + 1, l1) ||
                         Bit(i + 1, l1) && Bit(i + 1, l3) ||
                         Bit(i, l1) && Bit(i, l3) ||
                         Bit(i, l1) && Bit(i + 1, l2) || 
                         Bit(i + 1, l1) && Bit(i - 1, l2)
                       ) continue;
                    bad = true;
                    break;
                }
                if (!bad)
                    good2.push_back(make_pair(make_pair(l1, l2), l3));
            }
        }
    }    
    cerr << "OK" << endl;
    int n, m;
    cin >> n >> m;
    cout << Solve(n, m) << endl;

    return 0;
}
