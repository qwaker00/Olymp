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

int mi, a[111], n, was[111];


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {	
    	cin >> a[i];
    }
    sort(a, a + n);

    mi = int(2e9);

    if (n == 1) {
    	cout << 0 << endl;
    	return 0;
    }

    for (int d = 1; d <= (a[n - 1] - a[0]); ++d) {

	    int cnt = 0;
    	memset(was, 0, sizeof(was));
    	for (int x = a[0]; x <= a[n - 1]; x += d) {
    		int p = lower_bound(a, a + n, x) - a;
    		if (p < n && a[p] == x) {
    			was[p] = 1;
    		} else {	
    			++cnt;
    		}
    	}

		bool good = true;
		for (int i = 0; i < n; i++) if (!was[i]) {
			good = false;
			break;
		}
		if (good && cnt < mi) {
			mi = cnt;
		}
    }

    cout << mi << endl;

    return 0;
}
