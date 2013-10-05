#include <stdio.h>
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

typedef long long LL;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

LL a, b;
int p, k;

LL mulm(LL x, LL y, LL m) {
	LL res = 0;
	while (y) {
		if (y & 1) res = (res + x) % m;
		x = (x + x) % m;
		y >>= 1;
	}
	return res;
}

LL powm(LL x, LL y, LL m) {
	LL res = 1;
	while (y) {
		if (y & 1) res = mulm(res, x, m);
		x = mulm(x, x, m);
		y >>= 1;
	}
	return res;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> a >> b >> p >> k;

	if ((a % p) == 0 && (b % p) == 0) {
		cout << k << endl;
		return 0;
	}

	vector< pair<LL, int> > q;
	for (int i = 0; i <  p; ++i)
		if ((powm(a, i, p) + powm(b, i, p)) % p == 0) {
			q.push_back(make_pair(i, p));
			if (k == 1) {
				cout << i << endl;
				return 0;
			}
		}
	LL tf = 1;
	for (int i = 0; i < k; ++i) tf *= p;
	while (!q.empty()) {
		LL x = q.back().first;
		LL off = q.back().second;
		q.pop_back();

		LL off2 = off * p;
		LL step = off / p * (p - 1);
		if (off2 == tf) {
			for (int i = 0; i < p; ++i) {
				if ((powm(a, x, off2) + powm(b, x, off2)) % off2 == 0) {
					cout << x << endl;
					return 0;
				}
				x += step;
			}
		} else {
			for (int i = 0; i < p; ++i) {
				if ((powm(a, x, off2) + powm(b, x, off2)) % off2 == 0) {
					q.push_back(make_pair(x, off2));
				}
				x += step;
			}
		}
	}
	cout << -1 << endl;
	
	return 0;
}
