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

static const char LogTable256[256] = 
{
#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
    -1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
    LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
};

inline int level(unsigned int v) {
	unsigned r;
	register unsigned int t, tt;
	if (tt = v >> 16) {
		r = (t = tt >> 8) ? 24 + LogTable256[t] : 16 + LogTable256[tt];
	} else {
		r = (t = v >> 8) ? 8 + LogTable256[t] : LogTable256[v];
	}
	return r;
}
/*
inline unsigned int level(unsigned int v) {
	register unsigned int r;
	register unsigned int shift;

	r =     (v > 0xFFFF) << 4; v >>= r;
	shift = (v > 0xFF  ) << 3; v >>= shift; r |= shift;
	shift = (v > 0xF   ) << 2; v >>= shift; r |= shift;
	shift = (v > 0x3   ) << 1; v >>= shift; r |= shift;
    r |= (v >> 1);
	return r;
}*/

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int Q, inv = 0;
   	scanf("%d", &Q);
   	while (Q--) {
   		char t[3];
   		scanf("%s", t);
   		if (t[1] == 'i') inv ^= 1;else {
   			int ans[2];
   			unsigned x, y;
   			ans[0] = ans[1] = 0;
   			scanf("%u%u", &x, &y);

   			while ( level(x) > level(y) ) {
   				++ans[level(x) & 1];
   				x >>= 1;	
   			}
   			while ( level(y) > level(x) ) {
   				++ans[level(y) & 1];
   				y >>= 1;	
   			}
   			while (x != y) {
   				ans[level(y) & 1] += 2;
				x >>= 1;
				y >>= 1;
   			}
 			++ans[level(x) & 1];

 			printf("%d\n", ans[(t[1] == 'r') ^ inv]);
   		}
   	}
	
    return 0;
}
