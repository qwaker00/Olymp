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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
	cin >> T;   	
	while (T--) {
		LL n;
		cin >> n;
		bool found = 0;
		for (LL k = 1; 2 * n - k * k - k > 0; ++k) {
			if ( (2 * n - k * k - k) % (2 * (k + 1)) == 0 ) {
				LL a = (2 * n - k * k - k) / (2 * (k + 1));
				cout << n << " = " << a;
				for (int j = 1; j <= k; ++j) {
					++a;
					cout << " + " << a;
				}
				cout << "\n";

				found = 1;
				break;
			}
		}
		if (!found) {
			cout << "IMPOSSIBLE\n";
		}
	}

    return 0;
}
