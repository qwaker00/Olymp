#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll mypow(ll x, ll y) {
	ll res = 1;
	while (y--) res *= x;
	return res;
}

ll gcd(ll a, ll b) {
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int main() {
	freopen("in", "r", stdin);
	int T;
	cin >> T;

	while (T--) {
		int j1, j2, b1, b2;
		cin >> j1 >> j2 >> b1 >> b2;
		cout << j1 << " " << j2 << " " << b1 << " " << b2 << ": ";

		int p = 0, d = 0, all = 0;
		for (int i = j1; i <= j2; ++i)
			for (int j = b1; j <= b2; ++j) {
				ll v1 = mypow(i, j);
				ll v2 = mypow(j, i);

				++all;
				if (v1 > v2) ++p;
				if (v1 == v2) ++d;
			}

		ll num = p;
		ll den = all - d;

		ll D = gcd(num, den);
		num /= D; den /= D;
		cout << num << "/" << den << " " << den - num << "/" << den << endl;	
	}
}