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

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 333333
int n, p[N], le[N], ri[N], pos[N];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i< n; i++) {
		scanf("%d", &p[i]);
		pos[p[i]] = i;
		if (i > 0 && p[i-1] + 1 == p[i]) {
			le[i] = le[i-1] + 1;
		} else le[i] = 1;
	}
	for (int i = n-1; i >= 0;i--) {
		if (i < n - 1 && p[i + 1] - 1 == p[i]) {
			ri[i] = ri[i+1] + 1;
		} else ri[i] = 1;
	}

	LL ans = 0;
	for (int i = 0; i < n; i++) {
		if (pos[p[i] + 1] > i) {
			if (pos[p[i] + 1] == i + 1) {
				ans += le[i];
			} else
				ans += (LL)le[i] * ri[pos[p[i] + 1]];
		}
	}
	cout << ans << endl;


	return 0;
}
