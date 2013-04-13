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


int n, m, a[111][111];

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    int T;
	cin >> T;
	for (int __it = 1; __it <= T; ++__it) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
		}

		bool ok = true;
		for (int i = 0; i < n && ok; ++i)
			for (int j = 0; j < m && ok; ++j) {
				bool ok1 = true, ok2 = true;
				for (int k = 0; k < n; ++k)
					if (a[i][j] < a[k][j]) {
						ok1 = false;
						break;
					}
				for (int k = 0; k < m; ++k)
					if (a[i][j] < a[i][k]) {
						ok2 = false;
						break;
					}
				if (!ok1 && !ok2) ok = false;
			}

		printf("Case #%d: ", __it);
		puts(ok ? "YES" : "NO");
	}	    
    
    return 0;
}
