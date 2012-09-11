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

LL d[111];
int c[111], dn = 0;
LL x, ans;

void Rec(int i, LL x) {
	if (i == dn) {
		ans += x;
		return;
	}
	for (int j = 1; j <= c[i]; ++j) {
		x *= d[i];
		Rec(i + 1, x);
	}
}

bool prime[1000001];

int main() {
    freopen("divsum2.in", "r", stdin);
    freopen("divsum2.out", "w", stdout);

    cin >> x;
    for (int i = 2; i <= 1000; ++i) if (!prime[i]) {
    	if (x % i == 0) {
    		d[dn++] = i;
    		while (x % i == 0) {
    			++c[dn - 1];
    			x /= i;
    		}
    	}
    	for (int j = i * i; j <= 1000000; j += i) prime[j] = 1;
    }
    for (int i = 1001; i <= 1000000; i += 2) if (!prime[i] && x % i == 0) {
		d[dn++] = i;
		while (x % i == 0) {
			++c[dn - 1];
    		x /= i;
		}
    }

    if (x > 1) {
    	LL xx = (LL)(sqrt(x) + 1e-9);
    	if (xx * xx == x) {
    		d[dn++] = xx;
    		c[dn - 1] = 2;
    	} else {
    		d[dn++] = x;
    		d[dn - 1] = 1;
    	}
    }

    ans = 0;
    Rec(0, 1);
    cout << ans << endl;

    return 0;
}
