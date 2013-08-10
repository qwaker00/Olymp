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

LD a, b;

LD f(LD x) {
    return sqrtl( (a * a - x * x) * (b * b - x * x) );
}

int main() {
    freopen("twocyl.in", "r", stdin);
    freopen("twocyl.out", "w", stdout);


    cin >> a >> b;
    if (a > b) swap(a, b);

    const int N = 20000000;

    LD ans = 0;
    int c = 0;


    ans += f(0);
    ans += f(a);
    c = 2;
    for (int i = 1; i < N; i += 2) {
        ans += f(i * a / N) * 2;
        c += 2;
    }
    for (int i = 2; i < N; i += 2) {
        ans += f(i * a / N) * 2;
        c += 2;
    }
    ans /= c;

    cout.precision(12);
    cout << fixed << ans * 8 * a << endl;
    
    return 0;
}
