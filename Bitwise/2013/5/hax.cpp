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

int p[11111111];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T, n, m, d;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &d, &m);

        for (int i = 1; i <= n; ++i) p[i] = i;


        for (int i = 2; i * i <= d; ++i)
            if ((d % i) == 0) {
                for (int j = i; j <= n; j += i) {
                    while ((d % i) == 0 && (p[j] % i) == 0) {
                        d /= i;
                        p[j] /= i;
                    }
                    if (d % i) break;
                }
            }
        if (d > 1) 
        for (int j = d; j <= n; j += d)
            if ((p[j] % d) == 0) {
                p[j] /= d;
                d = 1;
            }

        if (d > 1)
            puts("-1");else {
                int mm = m;
                for (int i = 2; i * i <= mm; ++i)
                    if ((mm % i) == 0) {
                        for (int j = i; j <= n; j += i) {
                            while ((mm % i) == 0 && (p[j] % i) == 0) {
                                mm /= i;
                                p[j] /= i;
                            }
                            if (mm % i) break;
                        }
                    }
                if (mm > 1) 
                for (int j = mm; j <= n; j += mm)
                    if ((p[j] % mm) == 0) {
                        p[j] /= mm;
                        mm = 1;
                    }
                if (mm == 1) {
                    puts("0");
                } else {
                    LL res = m / mm;
                    for (int i = 1; i <= n; ++i) res = (res * p[i]) % m;
                    printf("%d\n", (int)res);
                }
            }
    }
    
    return 0;
}
