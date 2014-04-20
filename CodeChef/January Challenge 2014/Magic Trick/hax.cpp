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
typedef unsigned long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

inline LL Add(LL x, LL y, LL m) {
	return (x + y) % m;
}

inline LL Mul2(LL x, LL y, LL m) {
	LL ans = 0;
	while (y) {
		if (y & 1)
			ans = Add(ans, x, m);
		x = Add(x, x, m);
		y >>= 1;
	}
	return ans;
}
inline LL Mul3(LL x, LL y, LL m) {
	LL ans = 0;
	while (y) {
		switch (y & 3) {
			case 3: ans += x;
			case 2: ans += x;
			case 1: ans += x;
					ans %= m;
		}
		x += x;
		x += x;
		x %= m;
		y >>= 2;
	}
	return ans;
}
inline LL Mul(LL x, LL y, LL m) {
	LL ans = 0;
	while (y) {
		ans = (ans + (x * (y & 15))) % m;
		x = (x << 4) % m;
		y >>= 4;
	}
	return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T = 0;
    scanf("%d", &T);
    while (T--) {
    	static char s[1111];
    	static LL a[1111], A, B, C;
    	int n;

    	scanf("%d", &n);
    	for (int i = 0; i < n; ++i) {
    		scanf("%lld", &a[i]);
    	}
   		scanf("%lld", &A);
   		scanf("%lld", &B);
   		scanf("%lld\n", &C);
    	gets(s);
    	int L = 0, R = n, rev = 0;
    	LL Mu = 1, Ad = 0;
    	for (int i = 0; i < n; ++i) {
    		if (s[i] == 'R')
    			rev = 1 - rev;
    		else if (s[i] == 'A')
    			Ad = Add(Ad, A, C);
    		else if (s[i] == 'M') {
    			Mu = Mul(Mu, B, C);
    			Ad = Mul(Ad, B, C);
    		}
    		LL x;
    		if (rev) {
    			x = a[--R];
    		} else {
    			x = a[L++];
    		}
    		printf("%lld ", Add(Mul(x, Mu, C), Ad, C));
    	}
    	puts("");
    }
//    cerr << clock() << endl;
    
    return 0;
}
