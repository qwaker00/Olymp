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

struct Tp {
	int x;
	char y;
} a[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d\n", &n);
		LL cnt[2] = {0, 0};
		for (int i = 0; i < n; ++i) {
			scanf("%d %c\n", &a[i].x, &a[i].y);
			cnt[a[i].y == 'B'] += a[i].x;
		}
		if (cnt[0] == 0 || cnt[1] == 0) {
			cout << cnt[0] + cnt[1] << "\n";
			continue;
		}
		LL c[2] = {0, 0};
		int ans = 1;
		LL total = 0;
		for (int i = 0; i < n; ++i) {
			int col = (a[i].y == 'B');
			if ( (cnt[col] * c[1 - col]) % cnt[1 - col] == 0 ) {
				LL x = cnt[col] * c[1 - col] / cnt[1 - col] - c[col];
				if (x >= 0 && x < a[i].x && total + x > 0) {
					++ans;
					a[i].x -= x;
					c[0] = c[1] = 0;
					total = 0;
				}
			}
			c[col] += a[i].x;
			total += a[i].x;
		}
		printf("%d\n", ans);
	}

    return 0;
}
