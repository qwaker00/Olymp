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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define MOD 7340033

int g[4300][4300];
int n, k;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> k;
	if (k > n) {
		cout << 0 << endl;
		return 0;
	}	

	g[0][0] = 1;
	for (int j = 1; j <= n; ++j) {		
		g[0][j] = 0;
		for (int i = 1; i <= n; ++i) {
			g[i][j] = (g[i - 1][j] + g[i - 1][j - 1]) % MOD;                          	 
		}
	}
	int ans = 0;
	for (int st = 1; st * k <= n; ++st) {
		ans = (ans + g[n][st * k]) % MOD;
	}
	cout << ans << endl;
 
	return 0;
}
