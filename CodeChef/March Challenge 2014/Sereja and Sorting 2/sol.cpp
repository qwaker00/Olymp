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

const int N = 11111;
int n;
int res3, d[N];

void bsort(vector<int> g, int offset, bool bit, vector< pair<int, int> >& ans, int* d) {
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
                    res3 += n + g[i] + g[i + 1];
                    reverse(d + off, d + off + g[i] + g[i + 1]);

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
        res3 += n + g[0] + g[1];
        reverse(d + offset, d + offset + g[0] + g[1]);
    }
}

void rsort(int l, int r, int b, vector< pair<int, int> >& ans) {
    int len = r - l;
    int cur = -1, cnt = 0;
    vector<int> g;
    for (int i = 0; i < len; ++i) {
        int bi = (d[i + l] & (1 << b)) > 0;
        if (bi == cur) ++cnt;else {
            if (cnt > 0) g.push_back(cnt);
            cnt = 1;
            cur = bi;
        }
    }
    g.push_back(cnt);

    bsort(g, l, (d[l] & (1 << b)), ans, d);

    if (b > 0) {
        bool fnd = false;
        for (int i = 0; i < len; ++i) if ((d[i + l] & (1 << b)) > 0) {
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

int a[N], b[N], c[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }
    sort(b, b + n);

    LL res = 0;
    vector< pair<int, int> > ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            for (int j = i + 1; j < n; ++j) if (b[i] == a[j]) {
                ans.push_back(make_pair(i + 1, j + 1));
                res += n + j - i + 1;
                reverse(a + i, a + j + 1);
                break;
            }
        }                                       
    }

    LL res2 = 0;
    vector< pair<int, int> > ans2;
    for (int j = n - 1; j >= 0; --j) {
        if (c[j] != b[j]) {
            for (int i = j - 1; i >= 0; --i) if (b[j] == c[i]) {
                ans2.push_back(make_pair(i + 1, j + 1));
                res2 += n + j - i + 1;
                reverse(c + i, c + j + 1);
                break;
            }
        }                                       
    }

    if (res2 < res) {
        ans = ans2;
        res = res2;
    }

    vector< pair<int, int> > ans3;
    rsort(0, n, 15, ans3);

    if (res3 < res) {
        ans = ans3;
        res = res3;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }

    cerr << res << endl;

//    for (int i =0; i < n; ++i) cerr << a[i] << " ";
//    cerr << endl;
    
    return 0;
}