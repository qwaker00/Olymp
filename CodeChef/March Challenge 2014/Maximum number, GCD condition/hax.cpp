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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111111;

int n, m, pr[N], ia[N];
pair<int, int> a[N];
vector<int> b[N];
int mem[N * 33], memn, *AM[N], *LM[N], *RM[N];

inline int getmax(int x, int l, int r) {
    if (!b[x].size()) return 0;
    int* A = AM[x];
    int* L = LM[x];
    int* R = RM[x];
    l = lower_bound(b[x].begin(), b[x].end(), l) - b[x].begin() + 1;
    r = upper_bound(b[x].begin(), b[x].end(), r) - b[x].begin();
    if (l > r) return 0;

    int ans = 0;
    while ( ((l | (l - 1)) + 1) <= r ) {
        ans = max(ans, R[l]);
        l = ((l | (l - 1)) + 1);
    }
    ans = max(ans, A[l]);
    while ( (r & (r - 1)) >= l) {
        ans = max(ans, L[r]);
        r &= r - 1;
    }

    return ans;
}

inline void buildmax(int id) {
    int n = b[id].size();
    int* A = AM[id] = mem + memn; memn += n + 1;
    int* L = LM[id] = mem + memn; memn += n + 1; 
    int* R = RM[id] = mem + memn; memn += n + 1;

    for (int i = 1; i <= (int)b[id].size(); ++i) {
//        cerr << id << " " << i - 1 << endl;
        int x = a[ b[id][i - 1] ].first;

        A[i] = x;

        int p = i;
        while (p <= n) {
            L[p] = max(L[p], x);
            p = (p | (p - 1)) + 1;
        }
        p = i;
        while (p > 0) {
            R[p] = max(R[p], x);
            p = (p & (p - 1));
        }
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 2; i < N; ++i) if (pr[i] == 0) {
        for (int j = i; j < N; j += i)
            pr[j]  = i;
    }
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        ia[i] = x;
        a[i].second = i;
        a[i].first = x;

        int last = -1;
        while (x > 1) {
            if (pr[x] != last) {
                last = pr[x];
                b[last].push_back(i);
                //cerr << last << " " << i << endl;
            }
            x /= pr[x];
        }
    }
    for (int i = 0; i < N; ++i)
        if (b[i].size()) {
            buildmax(i);
        }
    sort(a + 1, a + n + 1);

  //  int __it = 0;
    while (m--) {
  //      ++__it;
        int x, l, r;
        scanf("%d%d%d", &x, &l, &r);

  /*      int ans2 = -1, ansc2 = -1;
        for (int i = l; i <= r; ++i) if (__gcd(ia[i], x) > 1) {
            if (ia[i] > ans2) {
                ans2 = ia[i];
                ansc2 = 1;
            } else
            if (ia[i] == ans2) {
                ++ansc2;
            }
        }
   */
        int ans = 0;
        int last = -1;
        while (x > 1) {
            if (pr[x] != last) {
                last = pr[x];
                ans = max(ans, getmax(last, l, r));
            }
            x /= pr[x];
        }
        pair<int, int>* lp = lower_bound(a + 1, a + n + 1, make_pair(ans, l));
        pair<int, int>* rp = upper_bound(a + 1, a + n + 1, make_pair(ans, r));
        int ansc = rp - lp;

        if (ans == 0) {
            ans = -1;
            ansc = -1;
        }

   //     if(ans != ans2 || ansc != ansc2) {
   //         cerr << __it << endl;
   //     }

        printf("%d %d\n", ans, ansc);
    }            
    
    return 0;
}
