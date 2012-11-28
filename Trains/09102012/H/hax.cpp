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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const ll p = 1000000007;

struct number {
    ll a, b;
    
    number(ll wa = 0, ll wb = 0) {
        a = wa;
        b = wb;    
    }

    number operator+(const number& A) const {
        return number((a + A.a) % p, (b + A.b) % p);
    }

    number operator-(const number& A) const {
        return number((a + p - A.a) % p, (b + p - A.b) % p);
    }

    number operator*(const number& A) const {
        return number( (((a * A.a) % p) + ((5 * b * A.b) % p)) % p, (((a * A.b) % p) + ((b * A.a) % p)) % p);
    }

    number operator *(ll x) const {
        return number((x * a) % p, (x * b) % p);
    }

    number operator +(ll x) const {
        return number((a + x) % p, b % p);
    }

    number operator-() const {
        return number(-a, -b);
    }
};

number mypow(number a, ll y) {
    number res(1, 0);
    while (y) {
        if (y & 1) res = res * a;
        a = a * a;
        y >>= 1;
    }
    return res;
}

void print(number a) {
    cout << a.a << " + (" << a.b << ")sqrt(5)" << endl;      
}

int main() {
    freopen("in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    number w1(1, 1), w2(1, -1);
    w1 = w1 * ((p + 1) / 2);
    w2 = w2 * ((p + 1) / 2);

    for (int i = 0; i < 20; ++i) {
        //print(mypow(w1, i) - mypow(w2, i));
    }

    ll n, k;
    cin >> n >> k;

    number res = mypow((-mypow(w1, n) + 1LL), k) * mypow(w1, k + 1) - mypow((-mypow(w2, n) + 1LL), k) * mypow(w2, k + 1);
    ll ans = res.b;
    if (k & 1) {
        ans = -ans;
    }
    while (ans < 0) ans += p;

    cout << ans << endl; 

    return 0;
}
