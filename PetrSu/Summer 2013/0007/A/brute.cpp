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

LL powm(LL a, LL b, LL m) {
	LL res = 1;
	while (b) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

int main() {
	freopen(".in", "r", stdin);
	freopen(".out2", "w", stdout);
	
	LL a, b, p, k;
	cin >> a >> b >> p >> k;
	LL p1 = 1;
	while(k--) p1 *=p;
	for (int i = 0; i < p1; ++i) {
		if ((powm(a, i, p1) + powm(b, i, p1)) % p1 == 0) {
			cout << i << endl;
//			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}
