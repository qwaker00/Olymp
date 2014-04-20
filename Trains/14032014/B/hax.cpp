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

const int N = 222222;

int n, k;
int a[N], h[N], hn = 0, f[N], A[N], L[N], R[N], p[N];

inline int next(int x) { return (x | (x - 1)) + 1; }
inline int prev(int x) { return (x & (x - 1)); }

inline void maximize(int& x, int y) {
    if (x == -1 || f[x] < f[y])
        x = y;
}

void update(int x, int y) {
    maximize(A[x], y);
    int l = x;
    while (l > 0) {
        maximize(L[l], y);
        l = prev(l);
    }
    int r = x;
    while (r < N) {
        maximize(R[r], y);
        r = next(r);
    }
}

int get_max(int l, int r) {
    if (l > r) return -1;

    int ans = -1;
    while (next(l) <= r) {
        maximize(ans, L[l]);
        l = next(l);
    }
    maximize(ans, A[l]);
    while (prev(r) >= l) {
        maximize(ans, R[r]);
        r = prev(r);
    }
    return ans;
}

//int ff[N], pf[N];

int main() {
    freopen("financial.in", "r", stdin);
    freopen("financial.out", "w", stdout);
    
    scanf("%d%d", &n, &k);
    --k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        h[hn++] = a[i];
    }
    sort(h, h + hn);
    hn = unique(h, h + hn) - h;

    
/*    int ansf = 0, bestf = 1;
    for (int i = 0; i < n; ++i) {
        ff[i] = 0;
        pf[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (fabs(a[j] - a[i]) > k && ff[j] > ff[i]) {
                ff[i] = ff[j];
                pf[i] = j;
            }
        }
        ++ff[i];
        if (ff[i] > ff[ansf]) {
            ansf = i;
            bestf = ff[i];
        }

        cerr << ff[i] << "," << pf[i] << " ";
    }
    cerr << endl;

    vector<int> outf;
    while (ansf != -1) {
        outf.push_back(ansf);
        ansf = pf[ansf];
    }
    printf("%d\n", outf.size());
    for(int i = (int)outf.size() - 1; i >= 0; --i) {
        printf("%d ", a[outf[i]]);
    }
    puts("");

*/
//    for (int i = 0; i < hn; ++i) cerr << h[i] << " ";
//    cerr << endl;

    memset(A, -1, sizeof(A));
    memset(L, -1, sizeof(L));
    memset(R, -1, sizeof(R));

    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int l = lower_bound(h, h + hn, a[i] - k) - h;
        int r = upper_bound(h, h + hn, a[i] + k) - h - 1;

//        cerr << a[i] << " " << l << " " << r << endl;

        int d = get_max(1, l);
        maximize(d, get_max(r + 2, N - 1));

//        cerr << d << endl;

//        cerr << f[-1] << endl;

        if (d == -1) f[i] = 1;else f[i] = f[d] + 1;
        p[i] = d;

        maximize(ans, i);

        update(lower_bound(h, h + hn, a[i]) - h + 1, i);

//        cerr << f[i] << " ";
    }
//    cerr << endl;


    vector<int> out;
    while (ans != -1) {
        out.push_back(ans);
        ans = p[ans];
    }

    printf("%d\n", out.size());
    for(int i = (int)out.size() - 1; i >= 0; --i) {
        printf("%d ", a[out[i]]);
    }
    puts("");

/*    if (out.size() != bestf) {
        cerr << "ERROR1" << endl;
        while (1);
    }
    for(int i = (int)out.size() - 1; i >= 1; --i) {
        if (abs(a[out[i]] - a[out[i - 1]]) <= k) {
            cerr << "ERROR2" << endl;
            while (1);
        }
    }
*/
    return 0;
}
