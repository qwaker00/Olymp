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

const ll MOD = 1234567891;
ll inverse25;

int powmod(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = (res * x) % MOD;
		y >>= 1;
		x = (x * x) % MOD;
	}                     
	return res;
}

int dist[444];

const int N = 20;
ll matrix[N][N];
ll result[N][N];
ll f[N][2];

ll vec[N];


struct cell {
	ll a[N][N];

	cell() {
		memset(a, 0, sizeof(a));
	}

	const cell operator*(const cell& A) const {
		cell result;
		for (int i = 0; i < N; ++i)
			for (int k = 0; k < N; ++k)
				for (int j = 0; j < N; ++j)
					result.a[i][j] = (result.a[i][j] + a[i][k] * A.a[k][j]) % MOD;
		return result;
	}	

	const cell operator+(const cell& A) const {
		cell result;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
					result.a[i][j] = (a[i][j] + A.a[i][j]) % MOD;
		return result;
	}
};
cell pows[33];

ll cres[N];

cell ed;
cell matrix_pow(int y) {
	cell res = ed;
	int it = 0;
	while (y) {
		if (y & 1) {
			res = res * pows[it];
		}
		++it;
		y >>= 1;
//		A = (A * A); 
	}
	return res;
}


cell matrix_sum(int y) {
	if (y == 0) {
		return cell();
	}
	if (y == 1) {
		return pows[0];
	}

	if (!(y & 1)) {
		cell half = matrix_sum(y / 2);
		return half + matrix_pow(y / 2) * half;
	}
	return matrix_sum(y - 1) * pows[0] + pows[0];
//	return matrix_sum(y - 1) + matrix_pow(y);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen(".out", "w", stdout);
	
	for (int i = 0; i < N; ++i) ed.a[i][i] = 1;

	inverse25 = powmod(25, MOD - 2);
	int T;
	cin >> T;
	while (T--) {
		int n;
		scanf("%d", &n);
		
		for (int i = 'a' - 1; i <= 'z'; ++i) {
			scanf("%d", dist + i);
		}

		memset(f, 0, sizeof(f));
		f[1][0] = 25;
		f[dist['a' - 1]][1] = 1;

		for (int i = 2; i < N; ++i) {
			f[i][0] += ll(25) * (f[i - 1][0] + f[i - 1][1]);
			for (int c = 'a'; c <= 'z'; ++c)
				if (c == 'r') {
					if (i > dist['r']) f[i][1] = (f[i][1] + f[i - dist['r']][1]) % MOD;
				} else {
					if (i > dist[c]) f[i][1] = (f[i][1] + f[i - dist[c]][0] * inverse25) % MOD;
				} 
			f[i][0] %= MOD;
			f[i][1] %= MOD;
		}

		memset(matrix, 0, sizeof(matrix));
		for (int i = 0; i < 18; ++i) {
			matrix[i][i + 2] = 1;
		}

		matrix[18][18] = 25;
		matrix[18][19] = 25;
		for (char c = 'a'; c <= 'z'; ++c) {
			if (c == 'r') {
				matrix[19][(10 - dist[c]) * 2 + 1] += 1;
			} else {
				matrix[19][(10 - dist[c]) * 2] += inverse25;
			}
		} 
		for (int i = 0; i < N; ++i) matrix[19][i] %= MOD;

		
		/*
		for (int i = 0; i < N; ++i)  {
			for (int j = 0; j < N; ++j) {
				cout << matrix[i][j] << " "; 
			}
			cout << endl;
		}
		*/
		

		int lim = min(n, N / 2);
		ll ans = 0;
		for (int i = 1; i <= lim; ++i) ans = (ans + f[i][0] + f[i][1]) % MOD;
		n -= lim;

		if (n == 0) {
			cout << ans << endl;
			continue;
		}

		for (int i = N - 1; i >= 0; --i) {
			if (i & 1) {
				vec[i] = f[1 + i / 2][1];
			} else {
				vec[i] = f[1 + i / 2][0];
			}
		}

		cell cur;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cur.a[i][j] = matrix[i][j];
		
		pows[0] = cur;
		for (int i = 1; i < 33; ++i)
			pows[i] = pows[i - 1] * pows[i - 1];	

		cur = matrix_sum(n);

		/*
		cout << "!" << endl;
		for (int i = 0; i < N; ++i)  {
			for (int j = 0; j < N; ++j) {
				cout << cur.a[i][j] << " "; 
			}
			cout << endl;
		}
		*/
		
		//for (int i = 0; i < N; ++i) cout << vec[i] << ' ';
		//cout << endl;
		memset(cres, 0, sizeof(cres));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cres[i] = (cres[i] + cur.a[i][j] * vec[j]) % MOD;
		//for (int i = 0; i < N; ++i) cout << cres[i] << ' ';
		//	cout << endl;

   		ans = (ans + cres[19] + cres[18]) % MOD;

   		cout << ans << endl;

	}


    return 0;
}
