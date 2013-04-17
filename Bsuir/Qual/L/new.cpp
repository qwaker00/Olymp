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
set< pair<string, int> > all;

LL dec(LL n, int mx) {
    if (n % 10) return n - 1;
    return dec(n / 10, mx) * 10 + mx;
}

LL Solve(LL n) {
    if (n == 0) return 0;

    if (n % 10 != 0) return Solve(n - n % 10) + n % 10;

    int mx = 0;
    LL x = n;
    while (x > 0) {
        if (x % 10 > mx) mx = x % 10;
        x /= 10;
    }

    return Solve(dec(n, mx)) + 1;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    LL n;
    cin >> n;    
    cout << Solve(n) << endl;
        
    return 0;
}
