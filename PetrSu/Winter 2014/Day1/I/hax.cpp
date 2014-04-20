#include <iostream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <climits>

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef long double ld;
const LD PI = 3.1415926535897932384626433832795;

template<typename T>
T sqr(const T& x) { return x * x; }

using namespace std;

const int N = 1001;

const int MOD = 1000000 + 3;
const int M = 31;

ll c[N][N];
int a[N];
int ones[33];
int pw2[33];

int main() {
	//freopen(".in","r", stdin);
	//freopen(".out","w", stdout);

	c[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	pw2[0] = 1;
	for (int i = 1; i < M; ++i) pw2[i] = (pw2[i - 1] + pw2[i - 1]) % MOD;

    int n;
    while (scanf("%d", &n) == 1) {
		memset(ones, 0, sizeof(ones));

		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			for (int j = 0; j < M; ++j) {
				if (a[i] & (1 << j)) ones[j]++;
			}
		}

		for (int day = 1; day <= n; ++day) {
			int ans = 0;
			for (int pw = 0; pw < M; ++pw) {
				int lim = min(ones[pw], day);
				for (int take = 1; take <= lim; take += 2) {
					ll vars = (ll(c[ ones[pw] ][take]) * c[n - ones[pw]][day - take]) % MOD; 
					ans = (ans + vars * (1 << pw)) % MOD;
				}
			}
			printf("%d ", ans);
		}
		puts("");
    }

	return 0;
}