#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

#define N 555555

int a[N], st[N], stn = 0, R[N], st2[N], stn2 = 0;

int main() {
    freopen("beacon.in", "r", stdin);
    freopen("beacon.out", "w", stdout);

    int n; 
    scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	                    /*
	int as = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int g = 1;
			for (int k = i + 1; k < j; ++k) if (a[k] > a[i] && a[k] > a[j]) g =0 ;
			as += g;
		}
	}
	cerr << as << endl;
	*/

	LL ans = 0;
	for (int i = 0; i < n; ++i) {
		while (stn > 0 && a[st[stn - 1]] <= a[i]) --stn;
		while (stn2 > 0 && a[st2[stn2 - 1]] < a[i]) --stn2;
		R[i] = stn2;

		if (stn > 0) {
			ans += i - st[stn - 1] + R[st[stn - 1]];
		} else {
			ans += i;
		}

		st[stn++] = i;
		st2[stn2++] = i;
	}
	cout << ans << endl;
    
    return 0;
}
