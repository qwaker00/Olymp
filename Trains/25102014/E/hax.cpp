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

LL gcd(LL x, LL y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    LL ax, ay, bx, by, cx, cy;
  	cin >> n >> ax >> ay >> bx >> by >> cx >> cy; 	 

  	LL d = ax * by - ay * bx;
  	LL dy = - cx * ay + cy * ax;
  	LL dx = - bx * cy + cx * by;

  	assert( d != 0 );
  	assert( ax * dx + bx * dy == d * cx );
  	assert( ay * dx + by * dy == d * cy );

  	LL ddx = llabs(d) / gcd(llabs(d), llabs(dx));
  	LL ddy = llabs(d) / gcd(llabs(d), llabs(dy));
  	LL ret = LL(ddx) * ddy / gcd(ddx, ddy);
  	
  	assert(LD(ret) * dx < 1e18);
  	assert(LD(ret) * dy < 1e18);
  	assert((ret * dx) % d == 0);
  	assert((ret * dy) % d == 0);
  	assert(ret > 0);
  	
  	LL deltax = ret * dx / d;
  	LL deltay = ret * dy / d;

  	LL ans = n * n;
  	for (int i = 0; i < n; ++i)
  		for (int j = 0; j < n; ++j) {
  			if (i + deltax >= 0 && i + deltax < n && j + deltay < n && j + deltay >= 0) {
  				ans += ret - 1;
  			} else {
  				ans += n - 1;
  			}
  		}
	cout << ans << endl;    
    return 0;
}
