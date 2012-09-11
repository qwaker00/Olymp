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

#define MOD 1000000007

typedef LL Matr[55][55];

Matr A, R, A2;
LL a[55], out[55];
int T, n, m, delta;

void Mul(Matr& C, const Matr& A, const Matr& B) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			LL& res = C[i][j] = 0;
			for (int k = 0; k < n; ++k) res = (res + A[i][k] * B[k][j]) % MOD;
		}
	}
}

void Power(Matr& Res, const Matr& A, int power) {
	Matr C, E;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Res[i][j] = (i == j);
	memcpy(E, A, sizeof(E));
	while (power) {
		if (power & 1) {
			Mul(C, Res, E);
			memcpy(Res, C, sizeof(C));
		}
		Mul(C, E, E);
		memcpy(E, C, sizeof(C));
		power >>= 1;
	}
//	while(power--) {
//		Mul(C, Res, A);
//		memcpy(Res, C, sizeof(C));
//	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> T;
	while (T--) {
		cin >> n >> m;
		delta = m % n;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		memset(A, 0, sizeof(A));
		for (int i = 0; i < n - 1; i++) A[i][i + 1] = 1;
		A[n - 1][1] = A[n - 1][n - 1] = A[n - 1][0] = 1;
		Power(R, A, m);

/*		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++)
				A2[i][j] = (i == j);
		for (int it = 0; it < m; it++) {
			int x = it % n;
			for (int j = 0; j < n; j++)
				A2[x][j] = (A2[x][j] + A2[(x + n - 1) % n][j] + A2[(x + 1) % n][j]) % MOD;
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; j++)
				if (A2[i][j] != R[(i - delta + n) % n][j])
					throw 1;
*/

		for (int it = 0; it < n; ++it) {
			for (int i = 0; i < n; ++i) {
				LL ans = 0;
				for (int j = 0; j < n; ++j) ans = (R[i][j] * a[j] + ans) % MOD;
				out[(i + delta + it) % n] = ans;
			}
			for (int i = 0; i < n - 1; ++i) cout << out[i] << " ";
			cout << out[n - 1] << endl;

			rotate(a, a + 1, a + n);
		}
		if (T) cout << endl;
	}

	return 0;
}
