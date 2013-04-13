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

int n, x, ans = 0;
map<int, int> cnt;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;

		if (x > 0) {
			int q = ++cnt[ x ];
			if (q == 3) {
				cout << -1 << endl;
				return 0;
			}
			if (q == 2) {
				++ans;
			}
		}
	}    
	cout << ans << endl;
    
    return 0;
}
