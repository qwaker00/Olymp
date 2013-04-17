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

LD big(9223372036854775808.);

char ch;
void readx(ULL& x) {
    while ( (ch = getchar()) < '0');
    x = ch - 48;
    while ( (ch = getchar()) >= '0') x = x * 10 + ch - 48;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int k;
    ULL n, w, h;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        readx(w);
        readx(h);
        readx(n);

        ULL left = 1;
        ULL right = min(w, h);
        while (left < right) {
            ULL center = left + ((right - left + 1) >> 1);
            if ( LD(w / center) * LD(h / center) >= big) {
                left = center;
            } else
            if ( (w / center) * (h / center) >= n) {
                left = center;
            } else
            {
                right = center - 1;
            }
        }
        printf("%I64lld\n", left);
    }
    
    return 0;
}
