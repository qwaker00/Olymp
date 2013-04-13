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
 
map<LL, unsigned> f[22];
unsigned ans[333333];

vector< LL > Q[19];
unsigned W[19][36105];
vector< vector<int> > GO[19];

int call = 0;

void recans(int p, int pp, int jj, unsigned& ans) {
    ans += W[18][p] * W[18][pp];
    for (int j = jj; j < 4; ++j) {
        int t1 = GO[18][p][j];
        int t2 = GO[18][pp][j];
        if (t1 == -1 || t2 == -1) continue;
        recans(t1, t2, j, ans);
    }
    ++call;
}


int main() {                            
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    f[0][1] = 1;
    for (int i = 0; i < 18; ++i) {
        for (map<LL, unsigned>::const_iterator j = f[i].begin(); j != f[i].end(); ++j) {
            for (int k = 1; k < 10; ++k)
                f[i + 1][j->first * k] += j->second;
        }
    }
    for (int i = 0; i <= 18; ++i) {
        vector< LL >& q = Q[i];
        unsigned* w = W[i];
        vector< vector<int> >& go = GO[i];
        q.reserve(f[i].size());
        go.reserve(f[i].size());
        int cnt = 0;
        for (map<LL, unsigned>::const_iterator j = f[i].begin(); j != f[i].end(); ++j) {
            q.push_back(j->first);
            w[cnt++] = j->second;
        }
        for (size_t k = 0; k < q.size(); ++k) {
            LL x = q[k];
            vector<int> to(4);
            to[0] = lower_bound(q.begin(), q.end(), x * 2) - q.begin();
            if (to[0] == q.size() || q[to[0]] != x * 2) to[0] = -1;
            to[1] = lower_bound(q.begin(), q.end(), x * 3) - q.begin();
            if (to[1] == q.size() || q[to[1]] != x * 3) to[1] = -1;
            to[2] = lower_bound(q.begin(), q.end(), x * 5) - q.begin();
            if (to[2] == q.size() || q[to[2]] != x * 5) to[2] = -1;
            to[3] = lower_bound(q.begin(), q.end(), x * 7) - q.begin();
            if (to[3] == q.size() || q[to[3]] != x * 7) to[3] = -1;
            go.push_back(to);
        }
    }

    LL v;
    int t, l, n;
    scanf("%d", &t);
    n = t;
    vector< pair< pair<int, LL>, int> > inp;
    inp.reserve(t);
    while (t--) {
        scanf("%d%I64d", &l, &v);
        inp.push_back(make_pair(make_pair(l, v), t));
    }
    sort(inp.begin(), inp.end());

    for (int i = 0; i < n; ) {
        int l = inp[i].first.first;
        int j = i;
        while (j < n && inp[j].first.first == l) ++j;

        vector<LL>& q = Q[(l + 1) >> 1];
        for (int k = i; k < j;) {
            int kk = k + 1;
            LL v = inp[k].first.second;
            while (kk < j && v == inp[kk].first.second) ++kk;

            unsigned result;
            if (v == 0) {
                ULL a1 = 9, a2 = 9;
                int l1 = (l - 1) >> 1, l2 = l - 1 - l1;
                for (int c = 0; c < l1; ++c) a1 *= 10, a2 *= 9;
                result = a1 - a2;
                for (int c = 0; c < l2; ++c) result *= 9;
            } else {
                int p = lower_bound(q.begin(), q.end(), v) - q.begin();

                result = 0;
                if (p == q.size() || q[p] != v) {
                } else {
                    recans(p, 0, 0, result);
                }
            }

            while (k < kk) {
                ans[n - inp[k].second - 1] = result;
                ++k;
            }
        }
        i = j;
    }
    for (int i = 0; i < n; ++i)
        printf("%u\n", ans[i]);

    cerr << clock() << endl;
    cerr << call << endl;

    return 0;
}
