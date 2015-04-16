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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int MOD = 1000000009;
const int N = 333;
int c[N][N];
int f[N][N][N];

void relax(int& x, int y) {
	x = (x + y) % MOD;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
    
    for (int i = 0; i < N; ++i) {
    	c[i][0] = c[i][i] = 1;
    	for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }

    f[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
    	for (int maxdepth = 0; maxdepth <= i; ++maxdepth)
    		for (int depth = 0; depth <= maxdepth; ++depth) {
    			if (depth) {
					relax(f[i + 1][maxdepth][depth - 1], f[i][maxdepth][depth]);
    			}
    			relax(f[i + 1][max(maxdepth, depth + 1)][depth + 1], f[i][maxdepth][depth]);
    		}
    }

    ll ans = 0;
    for (int i = 0; i <= n; ++i) {
    	ans = (ans + ll(f[i][k][0]) * c[n][i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
