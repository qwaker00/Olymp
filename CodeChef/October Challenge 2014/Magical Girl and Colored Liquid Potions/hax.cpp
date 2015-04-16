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

int main() {
 //   freopen(".in", "r", stdin);
 //   freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int a[3];
		int n[3], m;
		a[0] = a[1] = a[2] = 0;
		cin >> n[0] >> n[1] >> n[2] >> m;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < n[i]; ++j) {
				int x;
				cin >> x;
				if (x > a[i]) a[i] = x;
			}
		}
		int ans = *max_element(a, a + 3);
		for (int i = 0; i < m; ++i) {
			*max_element(a, a + 3) /= 2;
			ans = min(ans, *max_element(a, a + 3));
		}
		cout << ans << endl;
	}

    
    return 0;
}
