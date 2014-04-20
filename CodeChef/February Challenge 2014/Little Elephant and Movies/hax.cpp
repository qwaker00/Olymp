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

const int M = 1000000007;

inline void add(int& x, int y) {
	x = (x + y) % M;
}

inline int mul(int x, int y) {
	return (LL(x) * y) % M;
}

int a[222], f[222][222], fact[222], C[222][222], c[222], ss[222];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    fact[0] = 1;
    for (int i = 1; i < 222; ++i) fact[i] = mul(fact[i - 1], i);
    for (int i = 0; i < 222; ++i) {
    	C[i][0] = 1;
    	for (int j = 1; j <= i; ++j) {
    		C[i][j] = C[i - 1][j];
    		add(C[i][j], C[i - 1][j - 1]);
    	}
    }

    int T;
    cin >> T;
    while (T--) {
    	int n, l;
    	cin >> n >> l;
    	for (int i = 1; i <= n; ++i) cin >> a[i];
    	sort(a + 1, a + n + 1);

    	int an = 0;
    	for (int i = 1; i <= n; ++i) {
    		if (an == 0 || a[i] != a[an]) {
    			a[++an] = a[i];
    			c[an] = 1;
    		} else ++c[an];
    	}
    	n = an;

    	ss[an] = 0;
    	for (int i = n - 1; i >= 0; --i) ss[i] = ss[i + 1] + c[i + 1];

 		int ans = 0;
    	memset(f, 0, sizeof(f));
    	a[0] = -1;
    	f[0][0] = 1;
    	for (int i = 0; i < l; ++i) {
			for (int j = 0; j < n; ++j) if (f[i][j]) {
				int s = 0;
				for (int k = j + 1; k <= n; ++k) {
					s += c[k];
					add(f[i + 1][k], mul(f[i][j], mul(c[k], mul(C[s - 1 + ss[k]][s - 1], fact[s - 1]))));
				}
			}
    		add(ans, f[i][n]);
    	}
   		add(ans, f[l][n]);

		cout << ans << endl;
    }
    cerr << clock() << endl;
    
    return 0;
}
