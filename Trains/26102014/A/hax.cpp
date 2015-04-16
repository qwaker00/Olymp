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

int a[111][111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; ++i) {
		int c, x, y;
		cin >> c >> x >> y;
		a[x][y] = c;
	}
	int t;
	LL score = 0;
	cin >> t;
	while (t--) {
		char ch;
		int z, x, y;
		cin >> ch >> z >> x >> y;
		if (ch == 'U') {
			for (int j = 1; j <= n; ++j) {				
				bool prev = true;
				for (int i = 1, i2 = 1; i <= n; ++i) {
					if (a[i][j]) {
						if (!prev && a[i2 - 1][j] == a[i][j]) {
							a[i2 - 1][j] *= 2;
							score += a[i2 - 1][j];
							prev = true;
						} else {
							a[i2++][j] = a[i][j];
							prev = false;
						}
					}
					if (i >= i2) a[i][j] = 0;
				}
			}
		} else
		if (ch == 'D') {
			for (int j = 1; j <= n; ++j) {				
				bool prev = true;
				for (int i = n, i2 = n; i > 0; --i) {
					if (a[i][j]) {
						if (!prev && a[i2 + 1][j] == a[i][j]) {
							a[i2 + 1][j] *= 2;
							score += a[i2 + 1][j];
							prev = true;
						} else {
							a[i2--][j] = a[i][j];
							prev = false;
						}
					}
					if (i <= i2) a[i][j] = 0;
				}
			}
		} else
		if (ch == 'R') {
			for (int i = 1; i <= n; ++i) {
				bool prev = true;
				for (int j = n, j2 = n; j > 0; --j) {
					if (a[i][j]) {
						if (!prev && a[i][j2 + 1] == a[i][j]) {
							a[i][j2 + 1] *= 2;
							score += a[i][j2 + 1];
							prev = true;
						} else {
							a[i][j2--] = a[i][j];
							prev = false;
						}
					}
					if (j <= j2) a[i][j] = 0;
				}
			}
		} else
		if (ch == 'L') {
			for (int i = 1; i <= n; ++i) {
				bool prev = true;
				for (int j = 1, j2 = 1; j <= n; ++j) {
					if (a[i][j]) {
						if (!prev && a[i][j2 - 1] == a[i][j]) {
							a[i][j2 - 1] *= 2;
							score += a[i][j2 - 1];
							prev = true;
						} else {
							a[i][j2++] = a[i][j];
							prev = false;
						}
					}
					if (j >= j2) a[i][j] = 0;
				}
			}
		}

		a[x][y] = z;
	}
	cout << score << endl;
    
    return 0;
}
