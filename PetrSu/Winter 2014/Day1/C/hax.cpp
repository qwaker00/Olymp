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

string s[222];
int n, m, c, d;
int f[111][1033][11][22];

#define M 1000000007

inline void add(int& x, int y) {
	x = (x + y) % M;
//	x += y;
//	if (x >= M) x -= M;
}

int main() {
//	freopen(".in","r", stdin);
//	freopen(".out","w", stdout);
	
	while (cin >> n >> m >> c >> d) {
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		//memset(f, 0, sizeof(f));
		for (int i = 0; i <= n; ++i)
			for (int k = 0; k <= m; ++k)
				for (int j = 0; j <= (1 << m); ++j)
					for (int e = 0; e <= d; ++e) f[i][j][k][e] = 0;

		f[0][(1 << m) - 1][0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < m; ++k) {
				for (int j = 0; j < (1 << m); ++j) {
					for (int e = 0; e <= d; ++e) if (f[i][j][k][e]) {
//						cerr << i << " " << j << " " << k << " " << e << " = " << f[i][j][k][e] << endl;

						if ((j & (1 << k)) == 0) {
							add(f[i][j | (1 << k)][k + 1][e], f[i][j][k][e]);
//							cerr << "+" << i << " " << (j | (1 << k)) << " " << k + 1 << " " << e << endl;
						} else {
							if (s[i][k] == '1' && i + 1 < n && s[i + 1][k] == '1') {
								add(f[i][j ^ (1 << k)][k + 1][e], f[i][j][k][e]);
//								cerr << "+" << i << " " << (j ^ (1 << k)) << " " << k + 1 << " " << e << endl;
							}
							if (s[i][k] == '1' && k + 1 < m && s[i][k + 1] == '1' && (j & (1 << (k + 1)))) {
								add(f[i][j][k + 2][e], f[i][j][k][e]);
//								cerr << "+" << i << " " << j << " " << k + 2 << " " << e << endl;
							}
							if (s[i][k] == '1') {
								add(f[i][j][k + 1][e + 1], f[i][j][k][e]);								
//								cerr << "+" << i << " " << j << " " << k + 1 << " " << e + 1 << endl;
							}
							if (s[i][k] == '0') {
								add(f[i][j][k + 1][e], f[i][j][k][e]);
//								cerr << "+" << i << " " << j << " " << k + 1 << " " << e << endl;
							}
						}
					}
				}
			}
			for (int j = 0; j < (1 << m); ++j)
				for (int e = 0; e <= d; ++e)
					add(f[i + 1][j][0][e], f[i][j][m][e]);
		}
		int ans = 0;
		for (int i = c; i <= d; ++i)
			add(ans, f[n][(1 << m) - 1][0][i]);
		cout << ans << endl;

//		break;
	}

//	cerr << clock() << endl;

	return 0;
}