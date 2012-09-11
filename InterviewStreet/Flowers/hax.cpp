#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct Tp {
	int x, c;

	bool operator<(const Tp& B)const{
		return c < B.c;
	}
} a[111111];
int n, k;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x;
		a[i].c = a[i].x;
	}
	sort(a, a + n);

	LL ans = 0;
	int cc = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += a[i].x * (1 + cc / k);
		++cc;
	}
	cout << ans << endl;

	return 0;
}
