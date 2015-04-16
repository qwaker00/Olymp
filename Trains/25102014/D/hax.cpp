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

    int k;
	cin >> k;
	int n = 1;
	while (n * (n - 1) / 2 < k) ++n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		int rest = n - i;
		if (rest * (rest - 1) / 2 >= k) {
			a[i] = i;
		} else {
			a[i] = i + (k - (rest * (rest - 1) / 2));
			int x = n;
			for (int j = i + 1; j <= n; ++j) {
				if (x == a[i]) --x;
				a[j] = x;
				--x;
			}
			break;
		}
	}
	cout << n << "\n";
	for (int i = 1; i <= n; ++i) cout <<a[i] << " ";
	cout << "\n";
    
    return 0;
}
