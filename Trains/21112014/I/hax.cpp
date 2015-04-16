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

LD f[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    cout.precision(7);
    cout << fixed;

    int T;
    cin >> T;
    while (T--) {
    	LD P;
    	int n;
    	cin >> n >> P;
   		LD QP = 1 - P;
   		LD PM = 1;
	    LD ans = 0, last = 0;
    	for (int m = 0; m <= n; ++m) {
    		PM *= P;
    		QP *= P;

    		for (int j = 0; j <= m; ++j) f[j] = 1;
    		f[m + 1] = 1 - PM;
	    	for (int i = m + 1; i < n; i++)
	    		f[i + 1] = f[i] - QP * f[i - m - 1];

		    ans += (f[n] - last) * m;
		    last = f[n];
	    }
	    LL ansl = ans * 1e8 + 1e-7;
	    if (ansl % 10 >= 5) {
	    	ans = ((ansl / 10) + 1) / 1e7;
	    } else {
	    	ans = (ansl / 10) / 1e7;
	    }
	    cout << double(ans) << "\n";
    }

    return 0;
}
