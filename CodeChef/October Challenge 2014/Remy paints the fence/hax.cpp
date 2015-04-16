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

pair<int, char> a[111111];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);


    int T;
  	cin >> T;
  	while (T--) {
  		int n, m;
  		cin >> n >> m;
  		LL ans = 1;
  		for (int i = 0; i < m; ++i) {
  			cin >> a[i].second >> a[i].first;
  		}
  		sort(a, a + m);
  		for (int i = 1; i < m; ++i) {
  			if (a[i].second != a[i - 1].second)
  				ans = (ans * (a[i].first - a[i - 1].first)) % 1000000009;
  		}
  		cout << ans << "\n";
  	}

    
    return 0;
}
