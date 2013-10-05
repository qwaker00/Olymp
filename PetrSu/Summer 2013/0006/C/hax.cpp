//#define DEBUG
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>


typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
const LD PI = acos(-1.);
using namespace std;

int T;
LL  x;

#define MAX 20000001
bool pr[MAX];
LL primes[MAX / 10], pn = 0;
int c[111], dn = 0, take[111];
LL d[111];

inline bool isprime(LL x) {
	if (x < MAX) return !pr[x];
	if ((x & 1) == 0) return false;
//	cerr << x << endl;
	for (int j = 1; primes[j] * primes[j] <= x; ++j)
		if ((x % primes[j]) == 0)
			return false;
	return true;
}

int pretw[65536];

inline int Twos(LL x) {
	x = x - (x & (x - 1));
	if (x <= 65536) return pretw[x];
	return 16 + pretw[x >> 16];
}

void Gen2(LL n, LL x, LL mi, vector<LL>& ans) {
		if (Twos(n) == 0) {
			if (n == 1)
				ans.push_back(x);
//			cerr << x << endl;
		} else {
			if (n > mi && isprime(n + 1)) {
				bool bad = 0;
				for (int i = 0; i < dn; ++i)
					if (n + 1 == d[i] && take[i]) {
						bad = 1;
						break;
					}
				if (!bad)
					ans.push_back(x * (n + 1));
//				cerr << x * (n + 1) << endl;
			}
			for (LL p = mi + 2; p * p <= n; p += 2)
				if ((n % p) == 0) {
					if (isprime(p + 1)) {
						bool bad = 0;
						for (int i = 0; i < dn; ++i)
							if (p + 1 == d[i] && take[i]) {
								bad = 1;
								break;
							}
						if (!bad)
							Gen2(n / p, x * (p + 1), p, ans);
					}
				}
		}
}

void Gen(LL n, LL x, int i, vector<LL>& ans) {
	if (i == dn) {
		Gen2(n, x, 0, ans);
		return;
	}
	Gen(n, x, i + 1, ans);
	LL pp = d[i];
	take[i] = true;
	for (int j = 1; j <= c[i]; ++j) {
		n /= pp;
		x *= pp;
		if ((n % (pp - 1)) != 0) break;
		Gen(n / (pp - 1), x * pp, i + 1, ans);
	}
	take[i] = false;
}

LL phi(LL x) {
	LL ans = x;
	for (int i = 0; primes[i] * primes[i] <= x; ++i) {
		if ((x % primes[i]) == 0) {
			ans -= ans / primes[i];
			while ((x % primes[i]) == 0) x /= primes[i];
		}
	}
	if (x > 1)
		ans -= ans / x;
	return ans;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	{
		primes[pn++] = 2;
		pr[1] = 1;
		for (int i = 2; i < MAX; i += 2) pr[i] = 1;
		int i = 3;
		for (; i * i < MAX; i += 2) if (!pr[i]) {
			primes[pn++] = i;
			for (int j = i * i; j < MAX; j += i)
					pr[j] = 1;
		}
		while (i < MAX) { if (!pr[i]) { primes[pn++] = i; } i += 2; }
//		cerr << clock() << endl;
//		cerr << pn << endl;
		assert(pn < MAX / 10);
	}
	for (int i = 0; i <= 16; ++i) pretw[1 << i] = i;

	cin >> T;
	while (T--) {
		LL xx;		
		cin >> x;
		if (x == 1) {
			puts("2\n1 2");
			continue;
		}

		dn = 0;
		xx = x;
		for (int i = 0; primes[i] * primes[i] <= x; ++i) {
			if (x % primes[i] == 0) {
				c[dn] = 0;
				d[dn] = primes[i];
				while (x % primes[i] == 0) {
					++c[dn];
					x /= primes[i];
				}
				++dn;
			}
		}
		if (x > 1) {
			d[dn] = x;
			c[dn] = 1;
			++dn;
		}
		if (d[0] != 2) {
			puts("0\n");
			continue;
		}
		vector<LL> ans;
		Gen(xx, 1, 0, ans);
		for (size_t i = 0; i < ans.size(); ++i)
			if (ans[i] & 1)
				ans.push_back(ans[i] * 2);
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		#ifdef DEBUG
			cerr << "cheking..." << endl;
			for (size_t i = 0; i < ans.size();) {
				if (phi(ans[i]) != xx) {
//					ans.erase(ans.begin() + i);
					cerr << "phi(" << ans[i] << ") =  " << phi(ans[i]) << " != " << xx << endl;
					throw 1;
				} else ++i;
			}
		#endif

		cout << ans.size() << '\n';
		for (size_t i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
	cerr << clock() << endl;

	return 0;
}
