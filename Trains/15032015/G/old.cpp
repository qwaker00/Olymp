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

ULL a[222222];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n;
	scanf("%d", &n);   	 
	ULL tot = ULL(12) * 1000000 * 1000000;
	ULL sum = 0;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i] = (((ULL(x) * 1000000) + y) * 1000000) + z;
		sum += a[i];
	}
	for (int i = 0; i < n; ++i) a[i + n] = a[i] + tot; 
	sort(a, a + n);

	ULL sum1 = 0, sum2 = 0;
	ULL ans = 9e18;
	int c1 = 0;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < n + i && a[j] <= a[i] + tot / 2) {
			sum1 += a[j];
			sum2 += a[j];
			if (j >= n) sum2 -= tot;
			++c1;
			++j;
		}
		ans = min(ans, sum1 - a[i] * c1 + tot * (n - c1) - (sum - sum2) + (n - c1) * a[i]);
		--c1;
		sum1 -= a[i];
		sum2 -= a[i];
	}
	cout << ((ans / 1000000) / 1000000) << " "
		 << ((ans / 1000000) % 1000000) << " "
		 << (ans % 1000000) << endl;    
    return 0;
}
