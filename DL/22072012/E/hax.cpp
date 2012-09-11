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

#define MOD 366239

int d[11], dn = 0, a[11];
int x, y;
LL ans = 1;

int main() {
    freopen("product.in", "r", stdin);
    freopen("product.out", "w", stdout);

    cin >> x;
    while (x > 0) {
    	a[dn] = dn;
    	d[dn++] = x % 10;
    	x /= 10;
    }
    do {
    	y = 0;
    	for (int i = 0; i < dn; ++i) {
    		y = y * 10 + d[a[i]];
    	}
    	ans = (ans * y) % MOD;
    } while(next_permutation(a, a + dn));
	cout << ans << endl;    

    return 0;
}
