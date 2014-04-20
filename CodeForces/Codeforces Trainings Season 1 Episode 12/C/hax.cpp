#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int N;
    LD p;
    LL C[22][22];

	cin >> N >> p;

	memset(C, 0, sizeof(C));
	for (int i = 0; i < N; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}

	LD F[22], P[22 * 22];
	p = 1 - p;

	LD pp = 1;
	for (int i = 0; i <= N * N; ++i) {
		P[i] = pp;
		pp *= p;
	}

	F[1] = 0;
	for (int n = 2; n <= N; ++n) {
		F[n] = 0;
		for (int i = 1; i <= n - 1; ++i) {
			F[n] += C[n - 1][i - 1] * (1 - F[i]) * P[i * (n - i)];
		}
	}	
	cout.precision(20);
	cout << fixed << 1 - F[N] << endl;
    
    return 0;
}
