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


char s[1111111];
char p[33];
int to[33];
int c[33][33], cid[33], was[33], cpos[33];
int ans[33];
int rb[33], rc[33], rn;

bool valid(int x, int c) {
    for (int i = 0; i < rn; ++i) {
        int g = __gcd(c, rc[i]);
        if (x % g != rb[i] % g) return false;
    }
    return true;
}

void addrule(int b, int c) {
    rb[rn] = b;
    rc[rn] = c;
    ++rn;
}

void clear() {
    rn = 0;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d\n", &T);
    while (T--) {
        int n;
        memset(c, 0, sizeof(c));
        memset(was, 0, sizeof(was));
        int cn = 0;
        clear();

        scanf("%d\n", &n);
        gets(s);
        gets(p);

        for (int i = 0; i < 26; ++i) to[p[i] - 'a'] = i;
        for (int i = 0; i < 26; ++i) if (!was[i]) {
            int x = i;
            do {
                c[cn][++c[cn][0]] = x;
                cid[x] = cn;
                cpos[x] = c[cn][0] - 1;
                was[x] = 1;
                x = to[x];
            } while (x != i);
            ++cn;
        }

        memset(was, 0, sizeof(was));
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (was[cid[ch]]) {
                s[i] = ans[ch];
                continue;
            }
            int* cyc = c[cid[ch]] + 1;
            int  cl  = c[cid[ch]][0];
            int  p   = cpos[ch];

            int minc = 2e9, mi = -1;
            for (int it = 0; it < cl; ++it) {
                if (cyc[p] < minc && valid(it, cl)) {
                    minc = cyc[p];
                    mi = it;
                }
                if(++p == cl) p = 0;
            }
            addrule(mi, cl);
            for (int it = 0; it < cl; ++it) {
                ans[cyc[it]] = cyc[(it + mi) % cl] + 'a';
            }
            was[cid[ch]] = 1;

            s[i] = ans[ch];
        }
        puts(s);
    }    

    return 0;
}
