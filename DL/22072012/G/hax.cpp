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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


LL f[111][111], C[111][111];

int main() {
    freopen("separable.in", "r", stdin);
    freopen("separable.out", "w", stdout);
    LL hor, ver, ans = 0;
    int n, m;

    cin >> n >> m;

    hor = 1;
    for (int i = 0; i < m; i++) hor *= n + 1;

    ver = 1;
    for (int i = 0; i < n; i++) ver *= m + 1;

    ans += ver * 2 + hor * 2;

    memset(f, 0, sizeof(f));
    hor = 0;
    for (int i = 0; i <= n; i++) f[1][i] = 1;
    for (int i = 1; i < m; i++) {
    	f[i + 1][0] = f[i][0];
    	for (int j = 1; j <= n; j++) {
    		for (int k = 0; k <= j; k++) f[i + 1][j] += f[i][k];
    	}
    } 
    for (int i = 0; i <= n; i++) hor += f[m][i];

    memset(f, 0, sizeof(f));
    ver = 0;
    for (int i = 0; i <= m; i++) f[1][i] = 1;
    for (int i = 1; i < n; i++) {
    	f[i + 1][0] = f[i][0];
    	for (int j = 1; j <= m; j++) {
    		for (int k = 0; k <= j; k++) f[i + 1][j] += f[i][k];
    	}
    } 
    for (int i = 0; i <= m; i++) ver += f[n][i];


    for (int i = 0; i <= max(n, m); i++) {
    	C[i][0] = 1;
    	for (int j = 1; j <= i; j++) C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    
    ans -= hor * 2 + ver * 2;
    for (int i = 0; i <= n; i++) {
    	ans -= C[n][i];
    }
    for (int i = 0; i <= m; i++) {
    	ans -= C[m][i];
    }

    ans += (n ) * 2 + (m) * 2;

    ans -= 2;

    cout << ans << endl;

    return 0;
}
