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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
	cin >> T;
	cout.precision(12); cout << fixed;
	while (T--) {
		int x;
		LL k;
		cin >> x >> k;
		LL c = 1;
		while (c < k) {
			k -= c;
			c *= 2;
		}
		cout << (x * (double(0.5) / c + double(1) / c * (k - 1))) << "\n";
	}

    return 0;
}
