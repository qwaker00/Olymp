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
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    int T;
	cin >> T;
	while (T--) {
		int n, m, s = 0, mx = 0;
		cin >> n >> m;
		for (int i = 0 ; i < n; ++i) {
			int x;
			cin >> x;
			if (x > mx) mx = x;
			s += x;
		}
		s += m;
		if (s % n == 0 && s / n >= mx) {
			cout << "Yes\n";
		} else
			cout << "No\n";
	}
    
    return 0;
}
