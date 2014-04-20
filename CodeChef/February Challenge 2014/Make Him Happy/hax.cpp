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

int n, k, a[511111], was[1111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int l = 0, r = n - 1;
    while (l <= r) {
    	int x = a[l++];
    	was[x] = 1;
    	if (x <= k && k - x != x && was[k - x]) {
    		printf("%d\n", l);
    		return 0;
    	}
    	x = a[r--];
    	was[x] = 1;
    	if (x <= k && k - x != x && was[k - x]) {
    		printf("%d\n", l);
    		return 0;
    	}
    }
    puts("-1");

    return 0;
}