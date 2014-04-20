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

struct Tp {
	int x, b, p;
} a[111];
int f[111][111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d\n", &T);

	while (T--) {
		int n, B, P;
		scanf("%d%d%d", &n, &B, &P);

		memset(f, 128 + 63, sizeof(f));
		f[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &a[i].x, &a[i].b, &a[i].p);

			for (int j = B - a[i].b; j >= 0; --j)
				for (int k = P - a[i].p; k >= 0; --k)
					if (f[j + a[i].b][k + a[i].p] < f[j][k] + a[i].x)
						f[j + a[i].b][k + a[i].p] = f[j][k] + a[i].x;
		}
		int ans = 0;
		for (int i = 0; i <= B; ++i) for (int j = 0; j <= P; ++j)
			if (ans < f[i][j]) ans = f[i][j];
		cout << ans << endl;
	}
	

    return 0;
}
