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


int T, x, an, ans[1111111];
int pr[46666], pn, prime[46666], powprime[46666][31];


LL Calc(int c, int p) {
	LL ans = 0;
	for (int i = 0; i <= p; i++) {
		ans += powprime[c][i];
	}
	return ans;
}

void Rec(int i, int s) {
	int cur = 0;
	for (int j = 0; ; j++) {
		cur += powprime[i][j];
		if (LL(s) * cur > x) break;
		if (LL(s) * cur == x) {
			ans += 
			break;
		}

	}
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    memset(powprime, 127, sizeof(powprime));

    for (int i = 2; i < 45555; i++) if (!pr[i]) {
    	prime[pn] = i;

    	powprime[pn][0] = 1;
    	for (int j = 1; ; ++j) {
    		LL x = LL(powprime[pn][j - 1]) * i;
    		if (x > 1000000000) break;
    		powprime[pn][j] = x;
    	}

    	++pn;
    	
    	for (int j = i + i; j <= 45555; j += i) pr[j] = true;
    }

    cin >> T;
    while (T--) {	
	    cin >> x;
	
	    if (x == 1) {
	    	cout << 1 << endl;
	    	continue;
	    }

	    an = 0;
	    for (int p = 1; p <= 30; p++) {
	    	int left = 0, right = pn - 1;
			while (left < right) {
				int center = (left + right + 1) >> 1;
				LL c = Calc(center, p);
				if (c > x) right = center - 1;else left = center;
			}
			if (Calc(left, p) == x) {
				ans[an++] = powprime[left][p];
			}
	    }

	    Rec(0, 1);
	    sort(ans, ans + an);

	    if (an == 0) {
	    	cout << -1 << endl;
	    } else {
	    	for (int i = 0; i < an; i++) printf("%d ", ans[i]);
	    	puts("");
	    }

    }

    return 0;
}
