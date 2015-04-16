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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 2000111;
ll fact[N];

inline ll mypow(ll x, ll y, ll mod) {
	ll res = 1;
	while (y) {
		if (y & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res % mod;
}

inline ll justpow(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = (res * x) ;
		x = (x * x);
		y >>= 1;
	}
	return res;
}

inline ll inv(ll p, ll k) {
	return justpow(p, k) - justpow(p, k - 1);
}
int gcd(int a, int b) {
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}
inline int inv(int n) {
	int res = 0;
	for (int i = 1; i < n; ++i)
		if (gcd(i, n) == 1) ++res;
	return res;
}

pair<ll, ll> calc_fact(ll n, int p, int alpha, int whole) {
	if (n < whole) {
		ll rem = 1;
		ll cnt = 0;
		for (int i = 1; i <= n; ++i) {
			int cur = i;
			while (!(cur % p)) {
				cur /= p;
				++cnt;
			}
			rem = (rem * cur) % whole;
		}
		return make_pair(rem, cnt);
	}

	ll rem = (ll(mypow(fact[whole - 1], n / whole, whole)) * fact[n % whole]) % whole;
	ll cnt = (n / p);
	pair<ll, ll> prev = calc_fact(n / p, p, alpha, whole);
	pair<ll, ll> res = make_pair((rem * prev.first) % whole, cnt + prev.second);
	//cerr << n << "! % " << whole << " = (" << res.first << " " << res.second << ")" << endl; 
	return res; 
}

pair<int, int> calc(ll n, ll k, int p, int alpha, int whole) {
	fact[0] = 1;
	for (int i = 1; i < whole; ++i) {
		if ((i % p)) {
			fact[i] = (fact[i - 1] * ll(i)) % whole;
		} else {
			fact[i] = fact[i - 1];
		}
	}

	pair<ll, ll> f1 = calc_fact(n, p, alpha, whole);
	pair<ll, ll> f2 = calc_fact(k, p, alpha, whole);
	pair<ll, ll> f3 = calc_fact(n - k, p, alpha, whole);

	ll inverse = inv(p, alpha) - 1;
	ll rem = (f1.first * mypow(f2.first, inverse, whole)) % whole;
	rem = (rem * mypow(f3.first, inverse, whole)) % whole;
	ll cnt = f1.second - f2.second - f3.second;
	if (cnt >= alpha) {
		return make_pair(0, whole);
	}
	while (cnt--) {
		rem = (rem * p) % whole;
	}
	return make_pair(rem, whole); 	
}

int chinese(const vector<pair<int, int>>& A) {
	int m = 1;
	for (int i = 0; i < A.size(); ++i) {
		m *= A[i].second;
	}
	
	int result = 0;
	for (int i = 0; i < A.size(); ++i) {
		ll cm = m / A[i].second;
		ll add = A[i].first * cm * mypow(cm, inv(m) - 1, m);
		result = (add + result) % m;
	}
	return result;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
	
	ll n, k;
	int m;
	cin >> n >> k >> m;

	vector<pair<int, int>> A;
	int om = m;
	for (int d = 2; d <= om; ++d) {
		if (!(om % d)) {
			int cur = 1;
			int p = d;
			int cnt = 0;
			while (!(om % d)) {
				cur *= d;
				om /= d;
				++cnt;
			}
			A.push_back(calc(n, k, p, cnt, cur));
		}
	}

	//for (int i = 0; i < A.size(); ++i) cout << A[i].first << " " << A[i].second << endl;
	cout << chinese(A) << endl;

    return 0;
}
