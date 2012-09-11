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

int n, a[111], b[111];
LL f[1111111];
bool corr[1111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    }

    for (int i = 0; i < (1 << n); i++) {
    	corr[i] = true;
    	for (int j = 0; j < n; j++) if ((1 << j) & i) {
    		for (int k = 0; k < j; k++) if (!((1 << k) & i)) {
    			if (a[j] == a[k] && b[j] == b[k]) {
    				corr[i] = false;
    				break;
    			}
    		}
    		if (!corr[i]) break;
    	}
    }


    f[0] = 1;
    for (int i = 0; i < (1 << n); ++i) {
    	for (int j = 0; j < n; j++) if (((1<<j) & i) == 0 && corr[(1 << j) | i]) {
    		f[(1 << j) | i] += f[i];
    	}
    }
    cout << f[(1 << n) - 1] << endl;

    return 0;
}
