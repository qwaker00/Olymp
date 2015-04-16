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

LL ans = 2;
int ansc = 0;

LL n;
int d;

void check(LL base) {
	if (base < 2) return;

	LL nn = n;
	int c = 0;

	if (nn == 0 && 0 == d) {
		++c;
	}
	while (nn && nn % base == d) {
		++c;
		nn /= base;
	}

	if (c > ansc) {
		ansc = c;
		ans = base;
	} else if (c == ansc && base < ans) {		
		ans = base;
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	cin >> n >> d;

	LL nn = n - d;
	check(2);
	check(n + 1);
	check(d + 1);
	check(n);
	check(d);
	for (LL i = 1; i * i <= nn; ++i) if (nn % i == 0) {
		check(i);
		check(nn / i);
	}

	cout << ans << " " << ansc << endl;
    
    return 0;
}
