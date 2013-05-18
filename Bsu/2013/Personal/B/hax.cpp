#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

void Max(int& x, int y) {
	if (x < y) x = y;
}

int a[111];
int f[111][111][111];

int main() {
    freopen("bookshelf.in", "r", stdin);
    freopen("bookshelf.out", "w", stdout);
    
    int n;
	scanf("%d", &n);    

	a[0] = -1;
	a[1] = 101;
	for (int i = 2; i <= n + 1; ++i) scanf("%d", &a[i]);

	memset(f, 63 + 128, sizeof(f));
	f[2][0][1] = 0;
	for (int i = 2; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) 
			for (int k = 0; k <= n + 1; ++k) if (f[i][j][k] >= 0) {
				Max(f[i + 1][j][k], f[i][j][k]);

				if (a[i] >= a[j])
					Max(f[i + 1][i][k], f[i][j][k] + 1);

				if (a[i] <= a[k])
					Max(f[i + 1][j][i], f[i][j][k] + 1);
			}
	}

	int ans = 0;
	for (int i = 0; i <= n + 1; ++i)
		for (int j = 0; j <= n + 1; ++j)
			if (a[i] <= a[j])
				Max(ans, f[n + 2][i][j]);
	cout << ans << endl;
    
    return 0;
}

