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

LL pw(LL x, LL y) {
	LL res = 1;
	while (y) {
		if (y & 1) res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}

LL pk;
inline bool check(LL x) {
	return (powm(a, x, pk) + powm(b, x, pk)) % pk == 0;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> a >> b >> p >> k;

	if ((a % p) == 0 && (b % p) == 0) {
		cout << k << endl;
		return 0;
	}
	if ((a % p) == 0 && (b % p) != 0) {
		cout << -1 << endl;
		return 0;
	}
	if ((b % p) == 0 && (a % p) != 0) {
		cout << -1 << endl;
		return 0;
	}

	pk = pw(p, k);
    
	vector<LL> firs, secs;
	for (int i = 0; i < k; ++i) {
		firs.push_back(pw(p, i));
	}
	for (int i = 1; i * i <= p - 1; ++i) {
		if (!((p - 1) % i)) {
			secs.push_back(i);
			secs.push_back((p - 1) / i);
		}
	}

	vector<LL> guess;
	guess.push_back(1);
	guess.push_back(2);
	guess.push_back(5);
	guess.push_back(p);
	guess.push_back(pk);
	guess.push_back(pk - 1);

	for (int i = 0; i < guess.size(); ++i)
		if (check(guess[i])) {
			cout << guess[i] << endl;
			return 0;
		}

	for (int i = 0; i < firs.size(); ++i)
		for (int j = 0; j < secs.size(); ++j) {
			LL cand = firs[i] * secs[j];
			if (check(cand)) {
				cout << cand << endl;
				return 0;
			}
		}
	cout << -1 << endl;

	return 0;
}
