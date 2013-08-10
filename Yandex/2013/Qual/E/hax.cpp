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


int n, x, k;
int a[111111], rst[111111];

bool bymodx(int a, int b) {
    return a % x > b % x;
}

int main() {
    freopen("pratique.in", "r", stdin);
    freopen("pratique.out", "w", stdout);

    LL left = 1;
    LL right = 0;

    scanf("%d%d%d", &n, &x, &k);
    for (int i = 0; i < n; ++i) {        
        scanf("%d", &a[i]);
        right+= a[i];
    }
    if (x == 0) {
        cout << (right + k - 1) / k << endl;
        return 0;
    }

    sort(a, a + n, bymodx);
    while (left < right) {
        LL center = (left + right) / 2;

        LL days = center;
        for (int i = 0; i < n; ++i) {
            LL t = min(days, (LL)a[i] / x);
            days -= t;
            rst[i] = a[i] - t * x;
        }
        if (days) {
            for (int i = 0; i < n && days; ++i) {
                rst[i] = 0;
                --days;
            }
        }
        LL restall = 0;
        for (int i = 0; i < n; ++i) restall += rst[i];

        if ( (k == 0 && restall > 0) || (k > 0 && (restall + k - 1) / k > center) ) {
            left = center + 1;
        } else
            right = center;
    }

    cout << left << endl;
    
    return 0;
}
