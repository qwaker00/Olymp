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


int a[111111];
int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, mx = 0;
    scanf("%d", &n);
    for (int i =0 ; i < n; ++i) {
        scanf("%d", &a[i]);
        mx = max(mx, a[i]);
    }
    ULL left = mx;
    ULL right = mx + mx;
    while (left < right) {
        ULL c = (right + left) >> 1, v = 0;
        for (int i = 0; i < n; ++i) {
            if (c > a[i]) v += c - a[i];
        }
        if (v >= c) right = c;else left = c + 1;
    }    
    cout << left << endl;

    return 0;
}
