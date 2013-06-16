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


char s[111111];
int was[256];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    gets(s);
    int l = strlen(s);

    LL ans = 1;
    int let = 0;
    int letstart = 0;
    int ten = 0;

    for (int i = 0; i < l; ++i) {
        if (s[i] == '?') {
            if (i > 0) {
                ten++;
            } else ans *= 9;
        }
        if (s[i] >= 'A' && s[i] <= 'J') {
            if (was[s[i]]) continue;
            was[s[i]] = true;
            let++;
            if (i == 0) letstart = 1;
        }
    }
    if (letstart) {
        ans *= 9;
        int d = 9;
        for (int i = 1; d >= 0 && i < let; ++i) {
            ans *= d;
            d -= 1;
        }
    } else {
        int d = 10;
        for (int i = 0; d >= 0 && i < let; ++i) {
            ans *= d;
            d -= 1;
        }
    }
    cout << ans;
    for (int i = 0; i < ten; ++i) putchar('0');
    puts("");
    
    return 0;
}