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

LL powmod (LL a, LL b, LL p) {
	LL res = 1;
	while (b)
		if (b & 1)
			res = LL (res * 1ll * a % p),  --b;
		else
			a = LL (a * 1ll * a % p),  b >>= 1;
	return res;
}
 
LL generator (LL p) {
	vector<LL> fact;
	LL phi = p-1,  n = phi;
	for (LL i=2; i*i<=n; ++i)
		if (n % i == 0) {
			fact.push_back (i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back (n);
 
	for (LL res=2; res<=p; ++res) {
		bool ok = true;
		for (size_t i=0; i<fact.size() && ok; ++i)
			ok &= powmod (res, phi / fact[i], p) != 1;
		if (ok)  return res;
	}
	return -1;
}

LL SolveLog(LL a, LL b, LL m) {
	LL n = (LL) sqrt (m + .0) + 1;
	map<LL,LL> vals;
	for (LL i=n; i>=1; --i)
		vals[ powmod (a, i * n, m) ] = i;
	for (LL i=0; i<=n; ++i) {
		LL cur = (powmod (a, i, m) * b) % m;
		if (vals.count(cur)) {
			LL ans = vals[cur] * n - i;
			if (ans < m)
				return ans;
		}
	}
	return -1;
}

LL GcdEx(LL a, LL b, LL & x, LL & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	LL x1, y1;
	LL d = GcdEx(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

LL SolveRoot(LL k, LL c, LL n) {
	if (c == 0) return 0;

	LL G = generator(n);
	LL Gk = powmod(G, k, n);

	return powmod(G, SolveLog(Gk, c, n), n);
}

LL MinusMod(LL x, LL m) {
	if (x < 0) {
		return (m - ((-x) % m)) % m;
	}
	return x % m;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    LL T;
    cin >> T;
    while (T--) {
    	LL n, k, c, p, q;
		cin >> n >> k >> c;
		c %= n;
		for (LL i = 2; ; ++i) if (n % i == 0) {
			p = i;
			q = n / i;
			break;
		}
		LL x1 = SolveRoot(k, c % p, p);
		LL x2 = SolveRoot(k, c % q, q);
		LL x, y;
		GcdEx(p, q, x, y);
		y = -y;

		LL m;
		m = ((1ll * p * MinusMod(1ll * x * (x2 - x1), n)) + x1) % n;
		cout << m << endl;
	}

    return 0;
}
