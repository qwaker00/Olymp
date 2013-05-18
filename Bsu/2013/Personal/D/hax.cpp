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

int ans[3333], ed[3333];

typedef LL TMatr[333][333];

TMatr E, A, T;
int nn, n;
LL m;

void rec(int x, int msk) {	
	if (x > 1 && x < n) msk |= (1 << (x - 2));
	if (x + 1 <= n) rec(x + 1, msk);
	if (x + 2 <= n) rec(x + 2, msk);
	if (x + 3 <= n) rec(x + 3, msk);
	if (x == n) ans[msk]++;
}

#define MOD 1000000000

void Mul(TMatr& C, TMatr& A, TMatr& B) {
	for (int i = 0; i < nn; ++i) {
		for (int j = i; j < nn; ++j) if ((i & j) == i) {
			LL& s = C[i][j] = 0;
			for (int k = i; k <= j; ++k) {
				s += A[i][k] * B[k][j];
				if ((k & 7) == 0) s %= MOD;
			}
			s %= MOD;
		} else C[i][j] = 0;
	}
}

int main() {
    freopen("frog.in", "r", stdin);
    freopen("frog.out", "w", stdout);

    cin >> m >> n;

    if (n == 1) while(1);

    nn = (1 << (n - 2));
    m += m;

    rec(1, 0);

//    cerr << nn << endl;

    for (int i = 0; i < 1024; ++i) if (ans[i]) {
    	for (int j = 0; j < nn; ++j) {
    		A[j][j | i] += ans[i];
    	}
    }

    for (int i = 0; i < nn; ++i) E[i][i] = 1;
	while (m) {
		if (m & 1) {
			Mul(T, E, A);
			memcpy(E, T, sizeof(E));
		}
		Mul(T, A, A);
		memcpy(A, T, sizeof(E));
		m >>= 1;
	}

	LL ans2 = 0;
	ed[0] = 0;
	for (int i = 0; i < nn; ++i) {
		if (i > 0)
			ed[i] = ed[i & (i - 1)] + 1;
		if (ed[i] == n - 2 || ed[i] == n - 3) ans2 = (ans2 + E[0][i]) % MOD;
	}
	cout << ans2 << endl;
//	cerr << clock() << endl;
    
    return 0;
}

