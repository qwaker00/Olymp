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

int a[3333], n;


double calc1(int c, int d);

double calc2(int c, int d) {
    if (d > 25) return 0;
    if (c == 0) return 0;
    if (c == n * (n - 1) / 2) return 1 + calc1(c - 1, d + 1);
    return 1 + (calc1(c + 1, d + 1) + calc1(c - 1, d + 1)) / 2;
}                                           

double calc1(int c, int d) {
    if (c == 0) return 0;
    if (c == n * (n - 1) / 2) return 1 + calc2(c - 1, d + 1);
    return 1 + min(calc2(c + 1, d + 1), calc2(c - 1, d + 1));
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (int j = 0; j < i; ++j) if (a[j] > a[i]) {
            ++c;
        }
    }
    cout << c * 2 - (c & 1) << endl;

    return 0;
}
