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

int n, k, m, C[33][33], j;

int main() {
    freopen("combinations.in", "r", stdin);
    freopen("combinations.out", "w", stdout);

    for (int i = 0; i <= 30; i++) {
    	C[i][0] = 1;
    	for (int j = 1; j <= i; j++) C[i][j] = C[i-1][j-1]+C[i-1][j];
    }

    cin >> n >> k >> m;
    j = 0;
    for (int i = 0; i < k; i++) {
    	for (++j; j <= n; j++) {
    		if (C[n - j][k - i - 1] > m) {
    			cout << j << " ";
    			break;
    		} else m -= C[n - j][k - i - 1]; 
    	}
    }
    cout << endl;


    return 0;
}
