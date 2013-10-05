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


#define N 4222

LL a[N];
int del[N];
int id[N];
int n;
int pr[N];
int prc[N];
char ans[N+N];

int main() {
    freopen("codes.in", "r", stdin);
    freopen("codes.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        id[i] = i;
        del[i] = 0;
    }

    memset(pr, -1, sizeof(pr));
    int nn = n;
    for (int it = 1; it < n; ++it) {
        int prev = -1;
        LL mi = 1e18;
        int mii = 0, mij = 0;
        for (int i = 0; i < n; ++i) {
            if (del[i]) continue;
            if (prev == -1) {
                prev = i;
                continue;
            }
            if (a[id[prev]] + a[id[i]] < mi) {
                mi = a[id[prev]] + a[id[i]];
                mii = i;
                mij = prev;
            }
            prev = i;
        }
        a[nn] = a[id[mii]] + a[id[mij]];

        pr[id[mii]] = nn;
        prc[id[mii]] = '1';

        pr[id[mij]] = nn;
        prc[id[mij]] = '0';

        del[mij] = 1;
        id[mii] = nn;

        ++nn;
    }
    cerr << nn << endl;

    for (int i = 0; i < n; ++i) {
        int x = i;
        int an = N;
        ans[an] = 0;
        while (pr[x] != -1) {
            ans[--an] = prc[x];
            x = pr[x];
        }
        puts(ans + an);
    }
    
    return 0;
}
