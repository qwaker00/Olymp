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

int n, k, a[11111], ans[11111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n >> k;
    for (int i = 1; i < n; ++i) a[i] = 1;
    a[n] = 0;

    for (int it = 0; it < k; ++it) {
    	int ready = 0;
		for (int i = n; i > 0; --i) {
			if (a[i] == n - i && n - ready == i) {
				++ready;
				ans[i] = n;
			} else {
				if (a[i] + a[i] <= n - i) {
					ans[i] = i;
				} else {
					if (ready > 0 && a[i] + a[n - ready + 1] <= n - i) {
						ans[i] = n - ready + 1;
					} else {
						ans[i] = n - ((n - i) - a[i]);
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			a[i] += a[ans[i]];
			printf("%d ", ans[i]);
		}
		puts("");
    }
    for (int i = 1; i <= n; ++i) if (a[i] != n - i) throw 1;
    
    return 0;
}
