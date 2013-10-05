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

#define N 1111111

int a[N], n, pr[N], ansl = -1, anss = 0, anse = 0, last = 0;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    memset(pr, -1, sizeof(pr));
    last = 0;
    while (true) {
        scanf("%d", &a[n]);
        if (!a[n]) break;
        
        int prev = pr[ a[n] ];
        pr[ a[n] ] = n;

        if (prev >= last) last = prev + 1;
        if (n - last > ansl) {
            ansl = n - last;
            anss = last;
            anse = n;
        }

        ++n;
    }    
    if (n)
    for (int i = anss; i <= anse; ++i) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
