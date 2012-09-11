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

LL c[111][111];

LL C(int x, int y) {
	for (int i = 0; i <=x ; i++) {	
		c[i][0] = 1;
		for (int j = 1; j <= i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	return c[x][y];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int x1, y1, x2, y2;
    cin >> x1 >> x2 >> y1 >> y2;
	cout << C(x1, y1) * C(x2, y2) << endl;

    return 0;
}
