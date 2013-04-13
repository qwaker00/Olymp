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


LL n, k;
LL cr[111];


LL Pow(LL x, LL y, LL m) {
    LL c = 1;
    while (y) {
        if (y & 1) c = (c * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return c;
}

int main() {
 //   freopen(".in", "r", stdin);
 //   freopen(".out", "w", stdout);
    
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;

        for (int i = 0; i < k; ++i) cin >> cr[i];
        sort(cr, cr + k);

        LL fr = 1;
        LL last = 1;
        for (LL i = 1, j = 0; i <= 61; ++i) {
            if (j < k && cr[j] == 1) ++j;
            if (j < k && cr[j] == 2) ++j;
            if ( j < k && (1ll << i) == cr[j] ) {
                if (n >= (1ll << i)) {
                    ++fr;
                    last = 1ll << i;
                } else
                    last = n;
                ++j;
            } else {
                if (n >= (1ll << i)) {
                    last = (1ll << i);
                    fr += (1ll << (i - 1));
                } else {
                    fr += n - last;
                    last = n;
                }
            }
        }

        cout << Pow(2, fr, 1000000007) <<  endl;
    }
        
    
    return 0;
}
