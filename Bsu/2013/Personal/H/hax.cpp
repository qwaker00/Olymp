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

#define MOD 1000000007

inline void Add(int& x, int y) {
	x = (x + y) % MOD;
}

int main() {
    freopen("spiral.in", "r", stdin);
    freopen("spiral.out", "w", stdout);


    cin >> n >> m;
    if (n < m) swap(n, m);
    
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
    	f[i][0] = f[0][i] = i;
    	for (int j = 1; j <= m; ++j) {

    		int& ans = f[i][j];

    		Add(ans, j);
    		for (int k = 0; k < j; ++i) {
    			Add(ans, f[i][k]);
    		}

    		Add(ans, i);
    		for (int k = 1; k < i; ++i) {
    			Add(ans, f[i - 1][k]);
    		}

    		Add(ans, j);
    		for (int k = 1; k < j; ++i) {
    			Add(ans, f[i - 2][k]);
    		}

    		Add(ans, i);
    		for (int k = 1; k < i; ++i) {
    			Add(ans, f[i - 1][k]);
    		}
    	}
    }
    cout << f[i][j] << endl;
    
    return 0;
}

