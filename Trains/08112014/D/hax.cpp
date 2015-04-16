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

const int N = 1000111;
int buf[22];
int b[N];
int a[N];
LL f[N];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	b[0] = b[1] = b[2] = 1;
	for (int i = 2; i < n; ++i) {
		if ( (a[i] <= a[i - 1] && a[i-1]>=a[i - 2]) || (a[i]>=a[i-1] && a[i-1]<=a[i-2])) {
			if (a[i] == a[i - 1] && a[i-1] == a[i -2]) {
				// No ok
			} else {
				b[i] = b[i - 1] = b[i-2] = 1;
			}
		}
	}
	b[n - 1] = b[n - 2] = b[n- 3] = 1;

	int nn = 0;
	for (int i = 0; i < n; ++i) if (b[i])
		a[nn++] = a[i];
    n = nn;

	for (int i = 0; i < n; ++i) {
		int mi = a[i];
		int mx = a[i];
		for (int j = i, it = 0; j >= 0 && it < 25; --j, ++it) {
			mi = min(mi, a[j]);
			mx = max(mx, a[j]);
			f[i] = max(f[i], (j > 0 ? f[j - 1] : LL(0)) + (mx - mi));
		}
	}
	cout << f[n - 1] << endl;
    
    return 0;
}
