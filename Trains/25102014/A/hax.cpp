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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, k;
    LL ans = 0, ans2 = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
    	int x;
    	cin >> x;
    	if ((k & 1) == 1) {
	    	ans += x / k;
	    	ans2 |= ((x + 1) % k) == 0;
	    } else {
	    	ans += (x + 1) / k;
	    }
    }
    cout << ans + ans2 << endl;

    return 0;
}
