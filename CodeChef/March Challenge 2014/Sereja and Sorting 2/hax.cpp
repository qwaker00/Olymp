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

int n;
int a[33333];

void bsort(vector<int> g, int offset, bool bit, vector< pair<int, int> >& ans, int* a) {
    int st = 0;
    vector<int> ng;

    while (g.size() > 2) {
        int off = offset;
        ng.clear();
        if (bit == 0) {
            st = 1;
            off += g[0];
            ng.push_back(g[0]);
        } else st = 0;
        int tog = 1;
        for (int i = st; i < g.size(); i += 2) {
            if (i + 1 < g.size()) {
                if (tog == 1) {
                    ans.push_back(make_pair(off + 1, off + g[i] + g[i + 1]));
                    reverse(a + off, a + off + g[i] + g[i + 1]);

                    if (ng.size()) ng.back() += g[i + 1];else {
                        ng.push_back(g[i + 1]);
                        bit = 0;
                    }
                    ng.push_back(g[i]);
                } else {
                    ng.back() += g[i];
                    ng.push_back(g[i + 1]);
                }
                tog ^= 1;
                off += g[i] + g[i + 1];
            } else {
                if (tog == 1) {
                    ng.push_back(g[i]);
                } else {
                    ng.back() += g[i];
                }
                off += g[i];
            }
        }
        g.swap(ng);
    }
    if (g.size() == 2 && bit == 1) {
        ans.push_back(make_pair(offset + 1, offset + g[0] + g[1]));
        reverse(a + offset, a + offset + g[0] + g[1]);
    }
}

void rsort(int l, int r, int b, vector< pair<int, int> >& ans) {
    int len = r - l;
    int cur = -1, cnt = 0;
    vector<int> g;
    for (int i = 0; i < len; ++i) {
        int bi = (a[i + l] & (1 << b)) > 0;
        if (bi == cur) ++cnt;else {
            if (cnt > 0) g.push_back(cnt);
            cnt = 1;
            cur = bi;
        }
    }
    g.push_back(cnt);

    bsort(g, l, (a[l] & (1 << b)), ans, a);

    if (b > 0) {
        bool fnd = false;
        for (int i = 0; i < len; ++i) if ((a[i + l] & (1 << b)) > 0) {
            if (i > 0) {
                rsort(l, l + i, b - 1, ans);
                rsort(l + i, r, b - 1, ans);
                fnd = true;
            }
            break;
        }
        if (!fnd) rsort(l, r, b - 1, ans);
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }

    vector< pair<int, int> > ans;
    rsort(0, n, 15, ans);

    LL res = 0;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
        res += n + ans[i].second - ans[i].first + 1;
    }
    cerr << res << endl;
//    for (int i =0; i < n; ++i) cerr << a[i] << " ";
//    cerr << endl;
    
    return 0;
}
