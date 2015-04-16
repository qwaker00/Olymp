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
#include <cassert>

typedef long double LD;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 13;
const int M = 122;
int wholeM = 0;

const int K = 10011;
int absent[N][K];

int best[N], v[N];
bool got = false;
ll ansa = 0, ansb = 1;

ll f[N][M][M];
int prv[N][M][M];  
ll c[N];

ll myabs(ll x) {
	if (x < 0) return -x;
	return x;
}

ll gcd(ll a, ll b) {
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int main() {
    freopen("elections.in", "r", stdin);
    freopen("elections.out", "w", stdout);

	int n, s;
	ll V = 0;
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
		V += v[i];
		int cm = 0; cin >> cm;
		wholeM += cm;

		for (int j = 1; j < K; ++j) absent[i][j] = 1;
		for (int j = 0; j < cm; ++j) {
			int x;
			cin >> x;
			absent[i][x] = 0;
		} 

		for (int j = 1; j < K; ++j) absent[i][j] += absent[i][j - 1];
	}

    int limA = s + wholeM + 3;
	for (int A = s; A <= limA; ++A) {
		for (int i = 1; i <= n; ++i) c[i] = ll(A) * v[i]; 

		memset(f, 63, sizeof(f));
		memset(prv, -1, sizeof(prv));
		f[0][0][0] = 0;
		prv[0][0][0] = 123;

		for (int i = 1; i <= n; ++i) {
			for (int cura = 0; cura <= A; ++cura)
				for (int curb = 0; curb <= cura; ++curb) {
					for (int gota = 0; gota <= cura; ++gota) {
						int gotb = absent[i][gota];

					 	ll add = myabs(ll(gota) * V - c[i]);
						if (curb - gotb >= 0 && prv[i - 1][cura - gota][curb - gotb] != -1) {
							ll value = f[i - 1][cura - gota][curb - gotb] + add;
							if (prv[i][cura][curb] == -1 || value < f[i][cura][curb]) {
								prv[i][cura][curb] = gota;
								f[i][cura][curb] = value;
							}
						}
					}
				}
		}

		if (prv[n][A][s] == -1) continue;
		if (!got || ansa * V * A > f[n][A][s] * ansb) {
			got = true;
			ansa = f[n][A][s];
			ansb = V * A;
			ll d = gcd(ansa, ansb);
			if (d) {
				ansa /= d;
				ansb /= d;
			}
			int cura = A;
			int curx = n;
			int curb = s;
			while (curx) {
				int gota = prv[curx][cura][curb];
				int gotb = absent[curx][gota];
					
				best[curx] = gota;

				cura -= gota;
				curb -= gotb;
				curx -= 1;
			}	
		}	
	} 
	
	assert(got);
	for (int i = 1; i <= n; ++i) cout << best[i] << endl;

    return 0;
}
