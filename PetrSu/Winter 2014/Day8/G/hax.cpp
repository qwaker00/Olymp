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

char ans[1111111];

bool solve(int a, int b, int c, int n) {
	if (n == 0) return a == 0 && b == 0 && c == 0;
	while (n > 7) {
		if (a >= b && a >= c) {
			ans[n] = 'W';
			if (a < n) return false;
			a -= n;
		} else
		if (b >= a && b >= c) {
			ans[n] = 'G';
			if (b < n) return false;
			b -= n;
		} else {
			ans[n] = 'B';
			if (c < n) return false;
			c -= n;
		}
		--n;
	}
	if (a >= n && solve(a - n, b, c, n - 1)) {
		ans[n] = 'W';
		return true;
	}
	if (b >= n && solve(a, b - n, c, n - 1)) {
		ans[n] = 'G';
		return true;
	}
	if (c >= n && solve(a, b, c - n, n - 1)) {
		ans[n] = 'B';
		return true;
	}
	return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int a, b, c, n;
    cin >> a >> b >> c;
    LL s = LL(a) + b + c;
    n = 1;
    while (LL(n) * (n + 1) < 2 * s) ++n;
    
    ans[n + 1] = 0;
    if (LL(n) * (n + 1) != s * 2) {
    	puts("Impossible");
    } else {
    	if (!solve(a, b, c, n)) {
	    	puts("Impossible");
    	} else {
    		puts(ans + 1);
    	}
    }

    return 0;
}
