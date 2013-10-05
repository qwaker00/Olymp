#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 100003;
const int M = 303;
const int MOD = 1000000007;

int f[N][M][2];
int a[N];
int n;

int sum[M];

inline void relax(int& x, int y) {
	x = (x + y) % MOD;
}

int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i < min(a[0], a[1]); ++i) {
		f[1][ a[1] - i ][0] = 1;
	}
	f[1][ a[1] - min(a[1], a[0]) ][1] = 1;
	
	for (int i = 1; i + 1 < n; ++i) {
		memset(sum, 0, sizeof(sum));

		for (int j = 0; j <= a[i]; ++j) {
			if (j <= a[i + 1]) {
				relax(f[i + 1][ a[i + 1] - j ][1], f[i][j][0]);
			}

			int l = min(j, a[i + 1]);
			if (f[i][j][1]) {
				relax(f[i + 1][ a[i + 1] - l ][1], f[i][j][1]);
			}

			relax(sum[ a[i + 1] - l + 1 ], f[i][j][1]); 
		}

		int add = 0;
		for (int j = 0; j <= a[i + 1]; ++j) {
			relax(add, sum[j]); 

			relax(f[i + 1][j][0], add);
		}
	}
	
	int ans = 0;
	for (int j = 0; j <= a[n - 1]; ++j) {
		relax(ans, f[n - 1][j][1]);
	}

	cout << ans << endl;

	return 0;
}
