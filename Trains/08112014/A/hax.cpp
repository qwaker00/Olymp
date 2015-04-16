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

int popcnt(LL x) {
	int c = 0;
	while (x) {
		++c;
		x &= x- 1;
	}
	return c;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T;
	cin >> T;   	 
	while (T--) {
		LL l, r;
		cin >> l >> r;
		int ans = -1;
		LL anso = -1;
		for (int i = 0; i < 63 && l <= r; ++i) {
			int t = popcnt(l);
			if (t > ans) {
				ans = t;
				anso = l;
			}
			l |= LL(1) << i;
		}
		cout << anso << endl;
	}
    
    return 0;
}
