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

const LD eps = 1e-10;
using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    LD a, b, p, q, v1, v2;
	cin >> a >> b >> p >> q >> v1 >> v2;
	
	LD s  = min(a - p, a + p);
	LD t1 = (q - b) / v1;
	LD t2 = s / v2;
	if (t1 + eps > t2) {
		cout << (b / v1 + t2 * 2) << endl;
		return 0;
	}


	LD t;
	if ( fabs(v1 - v2) < eps ) {
		t = (s * s + sqr(b - q)) / (2 * (q - b) * v1);
	} else {
		LD A = v2 * v2 - v1 * v1;
		LD B = 2 * (q - b) * v1;
		LD C = -sqr(b - q) - s * s;
		LD D = B*B - 4 * A * C;
		t = max( (-B + sqrt(D)) / (2 * A),  (-B + sqrt(D)) / (2 * A) );
	}

	LD v2x = s / t;
	LD v2t = sqrt(v2 * v2 - v2x * v2x);
	LD dist = v2y * t;
	if (b / (v1 + v2)
    
    return 0;
}
