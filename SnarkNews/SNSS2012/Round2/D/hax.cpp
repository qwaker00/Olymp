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

int pr[211111];

int fs(int x) {
	if (pr[x] != x) pr[x] = fs(pr[x]);
	return pr[x];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, m, q, x, y;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) pr[i] = i;
    for (int i = 0; i < m; i++) {
    	scanf("%d%d", &x, &y);
    	x = fs(x), y = fs(y);
    	if (x != y) pr[x] = y;
    }
    for (int i = 0; i < q; i++) {
    	scanf("%d%d", &x, &y);
    	puts((fs(x) == fs(y)) ? "Yes": "No");
    }
    

    return 0;
}
