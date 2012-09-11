#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <functional>


typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111

int n, lastcommit, mi, a[N], b[N];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	int mi = (int)2e9, lastcommit = 0;
	a[0] = (int)-2e9;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < a[i - 1]) {
			b[i] = b[i - 1] - 1; 
		} else
		if (a[i] > a[i - 1]) {
			b[i] = b[i - 1] + 1;
		} else {
			while (++lastcommit < i) {
				b[lastcommit] -= mi - 1;
			}
			--lastcommit;

			mi = (int)2e9;
			b[i] = 0;
		}                                                 
		mi = min(mi, b[i]);
	}
	while (++lastcommit <= n) b[lastcommit] -= mi - 1;

	LL sum = 0;
	for (int i = 1; i <= n; ++i) sum += b[i];
	cout << sum << endl;
	
	return 0;
}
