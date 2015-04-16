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
  //  freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, k;
	scanf("%d%d", &n, &k);
	int l = 1;
	int r = n;
	for (int i = 0; i < k; ++i) {
		if ((i & 1) == 0) {
			if (i + 1 == k) {
				for (int j = r; j >= l; --j) printf("%d ", j);
				return 0;
			}
			printf("%d ", r);
			--r;
		} else {
			if (i + 1 == k) {
				for (int j = l; j <= r; ++j) printf("%d ", j);
				return 0;
			}
			printf("%d ", l);
			++l;
		}
	}

    return 0;
}
