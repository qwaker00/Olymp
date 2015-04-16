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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		int k, m;
		scanf("%d%d", &k, &m);

		vector<LL> coef(1, 1);
		LL f1 = 1;
		LL f2 = 1;
		for (int i = 0; i < k; ++i) {
			LL f3 = (f1 + f2) % m;
			f1 = f2;
			f2 = f3;
			coef.push_back(0);
			for (int j = int(coef.size()) - 2; j >= 0; --j) {
				coef[j + 1] = (coef[j + 1] - (coef[j] * f1) % m + m) % m;
			}
		}
		LL ans = 0;
		for (int i = 0; i < k; ++i) {
			int p;
			scanf("%d", &p);
			ans = (ans + coef[k - i] * p) % m;
		}
		ans = (m - ans) % m;
		printf("%d\n", (int)ans);
	}

    return 0;
}
