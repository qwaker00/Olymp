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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111111;

int n;
int a[N], s[N];

inline int prv(int x) {return x & (x-1);}

inline int nxt(int x) {return x + x - prv(x);}

int get(int l, int r) {
    int res = 0;
    for (; r; r = prv(r)) res += s[r];
    for (--l; l; l = prv(l)) res -= s[l];
    return res;

}

int put(int x) {
    while (x <= n) {
        s[x]++;
        x = nxt(x);
    }
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);

    int k = 2;

    int ans = 0;
    while (k--) {
        memset(s, 0, sizeof(s));
        int c = 0;
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            c = (c + get(x + 1, n)) & 1;
            put(x);
        }

        ans ^= c;    
    }

    if (ans) puts("Impossible");
    else puts("Possible");

    
    return 0;
}
