#include <iostream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <climits>

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef long double ld;
const LD PI = 3.1415926535897932384626433832795;

template<typename T>
T sqr(const T& x) { return x * x; }

using namespace std;

long double geom(ld b1, ld coef, ld n) {
	return b1 * (pow(coef, n) - 1) / (coef - 1);
}
ld s(ld n, ld k) {
	return 1. / k * ((n + 1) * pow(1. / k, n) * (1. / k - 1) - (pow(1. / k, n + 1) - 1)) / pow((1. / k - 1), 2); 
}

int main() {
	//freopen(".in","r", stdin);
	//freopen(".out","w", stdout);

	int n, k;
	cin >> n >> k;

	if (k == 1) {
		long double ans = ld(n) * (n + 1);
		cout.precision(15);
		cout << fixed;
		cout << ans / 2 << endl;
		return 0;
	}	
	
	ld ans = n;
	if (n >= 2) {
		ans += (n + 1) * geom(1. / k, 1. / k, n / 2);
		ans -= 2. * s(n / 2, k);
	}
	
	if (n >= 3) {
   		ans += n * geom(1. / k, 1. / k, (n - 1) / 2);
   		ans -= 2. * s((n - 1) / 2, k);
   	}

   	cout.precision(15);
   	cout << fixed;
   	cout << ans << endl;
	
	return 0;
}