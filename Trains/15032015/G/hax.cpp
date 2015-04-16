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

typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

ULL a[222222];

int main() {
//   freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	int n;
	scanf("%d", &n);   	 
	ULL tot = ULL(12) * 1000000 * 1000000;
	ULL sum = 0;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i] = (((ULL(x) * 1000000) + y) * 1000000) + z;
	}
	sort(a, a + n);

	for (int i = 1; i < n; ++i) {
		sum += tot - a[i] + a[0];
	}
	ULL ans = 9e18;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, sum);
		sum -= tot - a[i + 1] + a[i];
		sum += (a[i + 1] - a[i]) * (n - 1);
	}
	cout << ((ans / 1000000) / 1000000) << " "
		 << ((ans / 1000000) % 1000000) << " "
		 << (ans % 1000000) << endl;    
    return 0;
}
