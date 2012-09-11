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

#define N 555555

int n;
int a[N], ma1[N], mi1[N], ma2[N], mi2[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    while (1) {
    	scanf("%d", &n);
    	if (n == 1) break;
    	mi1[0] = mi2[n + 1] = (int)1e9;
    	ma1[0] = ma2[n + 1] = -(int)1e9;
    	for (int i = 1; i <= n; ++i) {
    		scanf("%d", &a[i]);
    		mi1[i] = min(mi1[i - 1], a[i]);
    		ma1[i] = max(ma1[i - 1], a[i]);
    	}
    	for (int i = n; i > 0; --i) {
    		mi2[i] = min(mi2[i + 1], a[i]);
    		ma2[i] = max(ma2[i + 1], a[i]);
    	}

    	int mindiff = 2e9, ans = 0;
    	for (int k = 1; k < n; ++k) {
    		int diff = max(ma1[k] - mi1[k], ma2[k + 1] - mi2[k + 1]);
    		if (diff < mindiff) {
    			mindiff = diff;
    			ans = k;
    		}
    	}
    	printf("%d\n", ans);
    }

    return 0;
}
