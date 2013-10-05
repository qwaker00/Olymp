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

#define N 111111
#define THRE 1111

int n, m, q;
LL a[N];
vector<int> V[N];
int big[N], bn = 0, isbig[N];
int mc[N][N / THRE];
LL sum[N], add[N];

inline void getint(int& x) {
    char ch;
    while ( (ch = getchar()) < '-' );
    if (ch == '-') {
        x = 0;
        while ( (ch = getchar()) >= '0' ) x = x * 10 + ch - 48;
        x = -x;
    } else {
        x = ch - 48;
        while ( (ch = getchar()) >= '0' ) x = x * 10 + ch - 48;
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        int x;
        getint(x);
//        scanf("%d", &x);
        a[i] = x;
    }
    int sk = 0;
    for (int i = 0; i < m; ++i) {
        int k;
        getint(k);
//        scanf("%d", &k);
        vector<int>& v = V[i];
        v.resize(k);
        for (int j = 0; j < k; ++j) {
            getint(v[j]);
//            scanf("%d", &v[j]);
            sum[i] += a[v[j]];
        }
        sort(v.begin(), v.end());
        sk += k;

        if (k > THRE) {
            big[bn++] = i;
            isbig[i] = 1;
        }
    }    
    scanf("\n");
    //cerr << sk << endl;
    //cerr << clock() << endl;

    for (int j = 0; j < bn; ++j) {
        const vector<int>& vj = V[big[j]];
        for (int i = 0; i < m; ++i) {
            const vector<int>& vi = V[i];

            int& c = mc[i][j] = 0;
            vector<int>::const_iterator ii = vi.begin(), jj = vj.begin();
            while (ii != vi.end() && jj != vj.end())
                if (*ii == *jj) {
                    ++c;
                    ++ii;
                    ++jj;
                } else
                if (*ii < *jj) {
                    ++ii;
                } else {
                    ++jj;
                }
        }
    }
    //cerr << clock() << endl;

    while (q--) {
        int k, x;
        char ch;
        scanf("%c %d", &ch, &k);
        --k;

        if (ch == '?') {
            if (isbig[k]) {
                printf("%I64d\n", sum[k]);
            } else {
                LL ans = 0;
                for (int i = 0; i < V[k].size(); ++i) {
                    ans += a[ V[k][i] ];
                }
                for (int i = 0; i < bn; ++i) {
                    ans += add[big[i]] * mc[k][i];
                }
                printf("%I64d\n", ans);
            }
        } else {
            scanf("%d", &x);
            if (isbig[k]) {
                add[k] += x;
            } else {
                for (int i = 0; i < V[k].size(); ++i) {
                    a[ V[k][i] ] += x;
                }
            }
            for (int i = 0; i < bn; ++i) {
                sum[big[i]] += LL(x) * mc[k][i];
            }
        }
        scanf("\n");
    }
    cerr << clock() << endl;

    return 0;
}