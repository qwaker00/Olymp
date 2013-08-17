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

typedef LL Matr[2][2]; 

inline void Mul(Matr& r, const Matr& x, const Matr& y, LL m) {
    r[0][0] = (x[0][0] * y[0][0] + x[0][1] * y[1][0]) % m;
    r[0][1] = (x[0][0] * y[0][1] + x[0][1] * y[1][1]) % m;
    r[1][0] = (x[1][0] * y[0][0] + x[1][1] * y[1][0]) % m;
    r[1][1] = (x[1][0] * y[0][1] + x[1][1] * y[1][1]) % m;
}

LL Fib(LL p, LL nn) {
    --p;

    Matr c;

    Matr r;
    r[0][1] = r[1][0] = 0;
    r[1][1] = r[0][0] = 1;

    Matr x;
    x[1][1] = 0;
    x[0][1] = x[0][0] = x[1][0] = 1;
    while (p) {
        if (p & 1) {
            Mul(c, r, x, nn);
            memcpy(r, c, sizeof(x));
        }
        Mul(c, x, x, nn);
        memcpy(x, c, sizeof(x));
        p >>= 1;
    }

    return r[0][0];
}

LL Calc(LL n) {
    LL nn = n;
    vector<LL> div;
    vector<LL> divc;
    for (LL i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            div.push_back(i);
            divc.push_back(0);
            while (n % i == 0) {
                n /= i;
                ++divc.back();
            }
        }
    if (n > 1) {
        div.push_back(n);
        divc.push_back(1);
    }

    if (divc.size() == 1 && divc.back() == 1) { //prime
        if (nn == 2) return 3;
        if (nn == 3) return 8;
        if (nn == 5) return 20;

        LL p = Fib(nn + 1, nn);
        if (p == 0) {

            LL dd = nn + 1, ans = dd;
            for (LL i = 1; i * i <= dd; ++i) if (dd % i == 0) {
                if (i < ans) {
                    LL p1 = Fib(i, nn);
                    if (p1 == 0) ans = i;
                }
                if (dd / i < ans) {
                    LL p1 = Fib(dd / i, nn);
                    LL p2 = Fib(dd / i + 1, nn);
                    if (p1 == 0) ans = dd / i;
                }
            }

            LL j = 1;
            while (true) {
                LL p1 = Fib(ans * j + 1, nn);
                if (p1 == 1) return ans * j;
                ++j;
            }
        } else {
            LL dd = nn - 1, ans = dd;
            for (LL i = 1; i * i <= dd; ++i) if (dd % i == 0) {
                if (i < ans) {
                    LL p1 = Fib(i, nn);
                    LL p2 = Fib(i + 1, nn);
                    if (p1 == 0) ans = i;
                }
                if (dd / i < ans) {
                    LL p1 = Fib(dd / i, nn);
                    LL p2 = Fib(dd / i + 1, nn);
                    if (p1 == 0) ans = dd / i;
                }
            }
            LL j = 1;
            while (true) {
                LL p1 = Fib(ans * j + 1, nn);
                if (p1 == 1) return ans * j;
                ++j;
            }
            return ans;
        }
    } else
    if (divc.size() == 1) { // prime^k
        LL ans = Calc(div[0]);
        for (LL i = 1; i < divc[0]; ++i) ans = ans * div[0];
        return ans;
    } else {
        LL ans = 1;
        for (LL i = 0; i < div.size(); ++i) {
            LL x = 1;
            for (LL j = 0; j < divc[i]; ++j) x *= div[i];
            LL subans = Calc(x);
            ans = ans / __gcd(ans, subans) * subans;
        }
        return ans;
    }
}

int main() {
    freopen("fibonacci.in", "r", stdin);
    freopen("fibonacci.out", "w", stdout);
/*    
    for (int r = 2; r <= 3000; ++r) {
        int f1 = 0;
        int f2 = 1;
        int it = 0;
        while (true) {
            ++it;
            int f3 = (f2 + f1) % r;
            f1 = f2;
            f2 = f3;
            cout << f3 << " ";

            if (f1 == 0 && f2 == 1) break;
        }
        cout << endl;
        cout << r << ": " << it << endl;
        
        if (it != Calc(r)) {
            cerr << "ERROR: " << r << endl;
        }
    }    
*/
    int n;
    cin >> n;
    cout << Calc(n) << endl;
   
    return 0;
}
