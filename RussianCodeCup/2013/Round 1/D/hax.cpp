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

vector<int> g[66666];
int ex[5111111], ey[5111111], en, eno[5111111];
int a[66666], ed[66666], l[66666], was[66666], b[66666], deg[66666];
int n, an = 0;

bool go(int x, int* a, int& an) {
    was[x] = true;
    vector< pair<int, int> > nei;
    for (int i = 0; i < g[x].size(); ++i) {
        int eid = g[x][i];
        if (ex[eid] == x) {
            if (!was[ey[eid]]) nei.push_back(make_pair(-deg[ey[eid]], ey[eid]));
        } else {
            if (!was[ex[eid]]) nei.push_back(make_pair(-deg[ex[eid]], ex[eid]));
        }
    }
    a[an++] = x;
    if (nei.size() > 0) {
        sort(nei.begin(), nei.end());
        deg[x]--;
        deg[nei[0].second]--;
        go(nei[0].second, a, an);
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    cin >> n;

    for (int i = 1; i < (1 << n); ++i) ed[i] = ed[i & (i - 1)] + 1;
    for (int i = 0; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j) if ((1 << j) & i)
            for (int k = 0; k < n; ++k) if (((1 << k) & i) == 0) {
                ex[en++] = i;
                ey[en - 1] = i ^ (1 << j) ^ (1 << k);
                g[i].push_back(en - 1);
                g[i ^ (1 << j) ^ (1 << k)].push_back(en - 1);
                deg[i]++;
                deg[i ^ (1 << j) ^ (1 << k)]++;
            }
//    cerr << en << endl;
//    cerr << "OK" << endl;

    a[an++] = 0;
    for (int i = 0; i < n; ++i) {
        int start = 0;
        for (int k = 0; k < n; ++k) if ((a[an - 1] & (1 << k)) == 0) {
            start = a[an - 1] ^ (1 << k);
            break;
        }
        int bn = 0;
        go(start, b, bn);
        for (int j = 0; j < bn; ++j) a[an++] = b[j];
//        cerr << i << endl;
    }

    if (an != (1 << n)) {
//        cerr << "error 2" << endl;
        throw 2;
    }
    memset(was, 0, sizeof(was));
    for (int i = an - 1; i >= 0; --i) {
//        printf("%d,", a[i]);
        for (int j = 0; j < n; ++j) putchar('0' + (((1 << j) & a[i]) > 0));
        puts("");
        fflush(stdout);

        if (i < an - 1 && (ed[a[i] ^ a[i + 1]] > 2 || ed[a[i]] > ed[a[i + 1]])) {
            throw 1;
        }
        if (was[a[i]]) throw 3;
        was[a[i]] = true;
    }
    
    return 0;
}
