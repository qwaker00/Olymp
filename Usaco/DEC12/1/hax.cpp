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

int n, m;
int a[1111111], b[1111111], an, bn;

using namespace std;
int main() {
    freopen("greetings.in", "r", stdin);
    freopen("greetings.out", "w", stdout);
	scanf("%d%d", &n, &m);

	int x;
	int ans = 0;
	
	x = 0;
	for (int i = 0; i < n; ++i) {
		int y; char c;
		scanf("%d %c", &y, &c);
		if (c == 'R') {
			while (y--) {
				a[an++] = ++x;
			}
		} else {
			while (y--) {
				a[an++] = --x;
			}
		}
	}
	x = 0;
	for (int i = 0; i < m; ++i) {
		int y; char c;
		scanf("%d %c", &y, &c);
		if (c == 'R') {
			while (y--) {
				b[bn++] = ++x;
			}
		} else {
			while (y--) {
				b[bn++] = --x;
			}
		}
	}
	a[an] = a[an - 1];
	b[bn] = b[bn - 1];

	bool meet = true;
	for (int i = 0, j = 0; i < an || j < bn;) {
		if (!meet && a[i] == b[j]) {
			++ans;
			meet = true;
		}
		if (meet && a[i] != b[j]) meet = false;

		if (i < an) ++i;
		if (j < bn) ++j;
	}
	cout << ans << endl;
	    
    return 0;
}
