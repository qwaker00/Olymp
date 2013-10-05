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

const int N = 200222;
const int MOD = 1000000007;
char w[N];
int cnt[11];
int f[6][1111];
int add[11];

const int M = 1111;
ll C[M][M];

void relax(int& x, ll y) {
	x = (ll(x) + y) % MOD;
}

int main() {
	freopen("can.in", "r", stdin);
	freopen("can.out", "w", stdout);	
	
	for (int i = 0; i < M; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}

	gets(w);
	int n = strlen(w);
	int m = 0;
	for (int i = 0; i < n; ++i) 
		if (w[i] == '?') ++m;
		else cnt[ w[i] - '0' ]++;


	int ans = 0;
	for (int a1 = 1; a1 <= 5; ++a1) {
		memset(add, 0, sizeof(add));
		add[a1] += 1;
		add[10 - a1] += 1;
		
		memset(f, 0, sizeof(f));
		f[0][m] = 1;

		for (int c0 = 0; c0 <= m; ++c0)
			for (int c9 = 0; c0 + c9 + add[0] + add[9] <= m; ++c9) {
				int sub = cnt[0] + c0 - cnt[0] - c9;
				if (sub >= 0 && !(sub & 1)) {
					relax(f[1][m - c0 - c9 - add[0] - add[9]], C[m][c0 + add[0]] * C[m - c0 - add[0]][c9 + add[9]]);
				}
			}	

		for (int i = 1; i < 5; ++i) 
			for (int j = 0; j <= m; ++j)
				if (f[i][j]) {
					int d1 = i, d2 = 9 - i;

					for (int c1 = 0; c1 <= j; ++c1) {
						int c2 = cnt[d1] + c1 - cnt[d2];

						int r1 = add[d1] + c1, r2 = add[d2] + c2;
						if (r1 + r2 <= j) {
							relax(f[i + 1][j - r1 - r2], ((C[j][r1] * C[j - r1][r2]) % MOD) * f[i][j]);
						}
					}
				}

		relax(ans, f[5][0]);
	}

	cout << ans << endl;

	return 0;
}
