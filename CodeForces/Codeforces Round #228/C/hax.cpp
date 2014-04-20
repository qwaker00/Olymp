#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int a[11111];
int b[11111], bn = 0;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int ans1 = 0, ans2 = 0;
    int n;
    cin >> n;
    for (int i = 0;i < n; ++i) {
    	int k;
	    cin >> k;
	    for (int j = 0; j < k; ++j) cin >> a[j];
	    if (k & 1) {
	    	for (int j = 0; j < k / 2; ++j) ans1 += a[j];
	    	for (int j = (k + 1) / 2; j < k; ++j) ans2 += a[j];
	    	b[bn++] = a[k / 2];
	    } else {
	    	for (int j = 0; j < k / 2; ++j) ans1 += a[j];
	    	for (int j = k / 2; j < k; ++j) ans2 += a[j];
	    }
    }
    sort(b, b + bn);
    for (int i = bn - 1; i >= 0; --i) {
    	if ((i + bn - 1) & 1) {
    		ans2 += b[i];
    	} else {
    		ans1 += b[i];
    	}
    }
    cout << ans1 << " " << ans2 << endl;

    return 0;
}
