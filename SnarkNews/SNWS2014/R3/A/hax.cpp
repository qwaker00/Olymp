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

int f[222222];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	int T;
	cin >> T;
	int* b = 0;
	if (*b)
	while (T--)	{
		int n, x;
		cin >> n >> x;
		memset(f, 128 + 63, sizeof(f));
		int s = 0;
		f[0] = 0;
		for (int i = 0; i < n; ++i) {
			int k;
			cin >> k;

			s += k;
			for (int j = s; j >= k; --j)
				f[j] = max(f[j], f[j - k] + 2 * k);
		}
		bool found = false;
		for (int j = 0; j <= s; ++j) if (f[j] >= x) {
			cout << j << endl;
			found = true;
			break;
		}
		if (!found)
			cout << -1 << endl;
	}
	
//    return 0;
}
