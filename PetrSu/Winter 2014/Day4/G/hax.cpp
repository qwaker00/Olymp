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

int T, n;
LL a[1111111];
int b[65];

bool zero(int* b) {
	for (int i = 0; i < 64; ++i) if (b[i] != 0) return false;
	return true;
}

void sub(LL x, int* b) {
	int i = 0;
	while (x) {
		if (x & 1)
			b[i] = (b[i] + 2) % 3;
		x >>= 1;
		++i;
	}
}

LL diff(int* b) {
	LL x = 0;
	for (int i = 64; i >= 0; --i) {
		x = x * 2;
		if (b[i] == 1) return -1;
		if (b[i] == 2) ++x;
	}
	return x;
}

void add(LL x, int* b) {
	int i = 0;
	while (x) {
		if (x & 1)
			b[i] = (b[i] + 1) % 3;
		x >>= 1;
		++i;
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &T);
    while (T--) {
    	scanf("%d", &n);
    	memset(b, 0, sizeof(b));
    	for (int i = 0; i < n; ++i) {
    		scanf("%I64lld", &a[i]);
    		add(a[i], b);
    	}
    	if (zero(b)) {
    		puts("C");
    	} else {
    		bool OK = false;
    		for (int i = 0; i < n; ++i) {
    			sub(a[i], b);
				LL x = diff(b);				
				if (x != -1 && x < a[i]) {
					OK = true;
					break;
				}
    			add(a[i], b);
    		}
    		if (OK) {
    			puts("A");
    		} else {
    			puts("B");
    		}
    	}
    }

    return 0;
}
