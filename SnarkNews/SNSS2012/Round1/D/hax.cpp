#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

LL Pow(LL x, LL y, LL m) {	
    LL res = 1;
    x %= m;
    while (y > 0) {
    	if (y & 1)
    		res = (res * x) % m;
		x = (x * x) % m;
		y >>= 1;
    }
    return res;
}

LL calc(LL x, LL y, LL m) {
	if (y == 1) return 1;
	LL t = calc(x, y >> 1, m);
	LL ans = (t + (Pow(x, y >> 1, m) * t) % m) % m;
	if (y & 1) ans = (ans * x + 1) % m;
	return ans;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    LL a, b, c;
    cin >> a >> b >> c;
    cout << calc(a, b, c) << endl;
    return 0;
}
