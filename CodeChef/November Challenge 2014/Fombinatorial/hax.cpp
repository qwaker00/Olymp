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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111111;
int pr[N], f[N];

LL powmod(LL x, LL y, LL m) {
	LL res = 1;
	while (y) {
		if (y & 1)
			res = (res * x) % m;
		x = (x * x) % m;
		y >>= 1;
	}
	return res;
}

struct tmul {
	int m;
	int phi;

	LL v;
	map<int, pair<LL, int> > vm;

	tmul(int m) : m(m), v(1) {
		phi = m;
		int x = m;
		for (int i = 2; i * i <= x; ++i)
			if (x % i == 0) {
				while (x % i == 0)
					x /= i;
				phi -= phi / i;
		}
		if (x > 1)
			phi -= phi / x;

//		for (int i = 1; i < m; ++i) if (__gcd(m, i) == 1)
//			assert(powmod(i, phi, m) == 1);
	}

	void mul(int x, int y) {
		if (m % x == 0) {
			vm[x].first += y;
			vm[x].second = -1;
		} else {			
			v = (v * powmod(x, y, m)) % m;
		}
	}

	void div(int x, int y) {
		if (m % x == 0) {
			vm[x].first -= y;
			vm[x].second = -1;
//			cerr << x << " " << vm[x] << endl;
		} else {
			v = (v * powmod(x, (phi - (y % phi)) % phi, m)) % m;
		}
	}

	LL val() {
		LL res = v;
		for (auto i = vm.begin(); i != vm.end(); ++i) {
			if (i->second.second == -1)
				i->second.second = powmod(i->first, i->second.first, m);
			res = (res * i->second.second) % m;
		}
		return res;
	}
};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 2; i <= 100000; ++i) if (!pr[i]) {
    	for (int j = i; j <= 100000; j += i) pr[j] = i;
    }

    int T;
    scanf("%d", &T);
	while (T--) {
		int n, m, q;
		scanf("%d%d%d", &n, &m, &q);

//        cerr << n << endl;   
		tmul ans(m);
		for (int i = 1; n - i >= i; ++i) {
			int x = n - i + 1;
			while (x > 1) {
				ans.mul(pr[x], n - i + 1);
				x /= pr[x];
			}
			x = i;
			while (x > 1) {
				ans.div(pr[x], i);
				x /= pr[x];
			}
			f[i] = ans.val(); 

//			cerr << f[i] << " ";
		}
//		cerr << endl;

		for (int i = 0; i < q; ++i) {
			int x;
			scanf("%d", &x);
			if (n - x < x) x = n - x;
			printf("%d\n", f[x]);
		}
	}

    return 0;
}
