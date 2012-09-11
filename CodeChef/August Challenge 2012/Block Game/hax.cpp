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

int n, ans[111], t[111][111], dead[111];


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cin >> t[i][j];
    	}
    }

    for (int i = 0; i < n; ++i) {
    	int ma = 1u << 31, man;
    	for (int j = 0; j < n; ++j) if (!dead[j] && t[j][i] > ma) {
    		man = j;
    		ma = t[i][j];
    	}
    	dead[man] = true;
    	ans[man] = i;
    }

    for (int i = 0; i < n - 1; ++i) cout << ans[i] + 1 << " ";    
    cout << ans[n - 1] + 1 << endl;

    return 0;
}
