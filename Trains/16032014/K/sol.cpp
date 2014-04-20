#include <iostream>
#include <stdio.h>

using namespace std;
typedef long long ll;

ll pw(ll x, ll y, ll p) {
    ll res = 1;
    while (y) {
        if (y & 1) res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res % p;
}

ll inv(ll x, ll y) {
    ll phi = y;

    ll cur = y;
    for (ll c = 2; c * c <= cur; ++c)
        if (!(cur % c)) {
            phi /= c;
            phi *= c - 1;

            while (!(cur % c)) {
                cur /= c;
            }
        } 
    if (cur != 1) {
        phi /= cur;
        phi *= cur - 1;
    }

    return pw(x, phi - 1, y);
}

ll edins(ll cnt, ll mod) {
    if (cnt == 0) return 0;
    if (cnt == 1) return 1 % mod;
    if (cnt & 1) {  
        return (edins(cnt - 1, mod) * 10 + 1) % mod;
    }
    ll t = edins(cnt >> 1, mod);
    return ((t * pw(10, cnt >> 1, mod)) % mod + t) % mod;
}


int main() {
    freopen("zeroes.in", "r", stdin);
    freopen("zeroes.out", "w", stdout);    
    
    ll k, p;
    cin >> k >> p;

    if (p == 1) {
        cout << 0 << endl;
        return 0;
    }


    ll ans = k + ((k - 1) % p) * pw(10, k - 1, p);
    ll add = edins(k - 1, p);
    ans %= p; 
    ans -= add;

    ans %= p;
    if (ans < 0) ans += p;

    cout << ans << endl;

    return 0;
}