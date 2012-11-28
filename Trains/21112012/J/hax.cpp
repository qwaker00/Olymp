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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

inline LL Count(LL a, LL p, LL q) {
    return a - (a / p + a / q - a / (p * q) );
}

LL Solve(LL a, LL p, LL q) {
    if (a == 0) return 0;

    LL ans = 0;
    LL pp = p;
    for (int i = 1; true; i++) {
        LL qq = 1;
        for (int j = 0; j < i; j++) {
            ans += Count(a / (pp * qq), p, q);
            if (LD(qq) * pp * q > LD(a)) break;
            qq *= q;
        }
        if (LD(pp) * p > LD(a)) break;
        pp *= p;
    }

    return ans;
}


int main() {
    freopen("jealous.in", "r", stdin);
    freopen("jealous.out", "w", stdout);

    LL a, b, p, q;
    cin >> a >> b >> p >> q;
    cout << Solve(b, p, q) - Solve(a - 1, p, q) << endl;
    
    return 0;
}
