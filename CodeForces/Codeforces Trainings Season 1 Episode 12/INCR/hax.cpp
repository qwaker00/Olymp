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

const int N = 47;
const int MOD = 1000000000;
int f[N][N][N][N][N];

inline void add(int& x, int val) {
	x = (x + val) % MOD;
}

void getans(int n, int b) {
    int ans = 0;
	if (b == 1) {
		ans = f[n - 1][n][n + 1][n + 2][n + 3];
	} else if (b == 2) {
		for (int p2 = 0; p2 < n; ++p2)
			add(ans, f[n - 1][p2][n + 1][n + 2][n + 3]);
	} else if (b == 3) {
		for (int p2 = 0; p2 < n; ++p2)
			for (int p3 = 0; p3 < n; ++p3)
				add(ans, f[n - 1][p2][p3][n + 2][n + 3]);
	} else if (b == 4) {
		for (int p2 = 0; p2 < n; ++p2)
			for (int p3 = 0; p3 < n; ++p3)
				for (int p4 = 0; p4 < n; ++p4)
				add(ans, f[n - 1][p2][p3][p4][n + 3]);
	} else if (b == 5) {
		for (int p2 = 0; p2 < n; ++p2)
			for (int p3 = 0; p3 < n; ++p3)
				for (int p4 = 0; p4 < n; ++p4)
					for (int p5 = 0; p5 < n; ++p5)
						add(ans, f[n - 1][p2][p3][p4][p5]);		
	}

	printf("\tans[%d][%d] = %d;\n", n, b, ans);
}

int main() {
    //freopen("incr.in", "r", stdin);
    //freopen("incr.out", "w", stdout);

    int n, b;
	cin >> n >> b;

	f[0][1][2][3][4] = 1;
	for (int i = 0; i + 1 < n; ++i) {
		int lim2 = i + 1;
		int lim3 = i + 2;
		int lim4 = i + 3;
		int lim5 = i + 4;
		for (int p2 = 1; p2 <= lim2; ++p2)
			for (int p3 = p2 + 1; p3 <= lim3; ++p3)
				for (int p4 = p3 + 1; p4 <= lim4; ++p4)
					for (int p5 = p4 + 1; p5 <= lim5; ++p5) {
						int val = f[i][p2][p3][p4][p5]; 
						if (val == 0) continue;

						add(f[i + 1][p2 + 1][p3 + 1][p4 + 1][p5 + 1], val);
					    for (int pos = 1; pos <= lim2; ++pos) {
					    	if (pos <= p2) {
								add(f[i + 1][pos][p3 + 1][p4 + 1][p5 + 1], val);
					    		continue;
					    	}
					    	if (pos <= p3) {
					    		add(f[i + 1][p2][pos][p4 + 1][p5 + 1], val);
					    		continue;
					    	}
					    	if (pos <= p4) {
					    		add(f[i + 1][p2][p3][pos][p5 + 1], val);
					    		continue;
					    	}
					    	if (pos <= p5) {
					    		add(f[i + 1][p2][p3][p4][pos], val);
					    		continue;
					    	}
						}
					}
	}

	/*
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n + 1; ++j)
			for (int k = 0; k <= n + 2; ++k)
				for (int t = 0; t <= n + 3; ++t)
					for (int q = 0; q <= n + 4; ++q)
						if (f[i][j][k][t][q]) cerr << i << ": " << j << ", " << k << ", " << t << ", " << q << " = " << f[i][j][k][t][q] << endl;
	*/

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= b; ++j)
			getans(i, j);

    
    return 0;
}
