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


#define MOD 1000000007

//LL pw[11111111], fact[11111111];
LL a[11111111];
/*

inline int Pow(int x, int y) {
    LL res = 1;
    while (y) {
        if (y & 1)
            res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
} 

inline LL Div(LL x, LL y) {
    return (x * Pow(y, MOD - 2)) % MOD;
}

int GetC(int n, int m) {
    if (m == 0) return 1;
    return Div(Div(fact[n], fact[n - m]), fact[m]);
}
*/

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> m >> n;

        a[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i >= m)
                a[i] = (a[i - 1] * m - a[i - m] + MOD) % MOD;else
                a[i] = (a[i - 1] * m) % MOD;
        }
        cout << a[n] << endl;
    }
//    cerr << clock() << endl;
    
    return 0;
}
