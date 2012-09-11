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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n;
int a[111111];

long double Log3 = (long double)(1.5849625007211561814537389439478);

struct Tp {
	int p3, p2;

	Tp(int p3 = 0, int p2 = 0) {
	}

	bool operator<(const Tp& B) const {
		return p2 + p3 * Log3 < B.p2 + B.p3 * Log3;
	}
} f[111111];

int pr[111111];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	memset(f, -1, sizeof(f));
	f[0] = 1;
	for (int i = 1; i <= n; i++) {                 	
		int state = 0;
		for (int j = 1; j < 4 && i - j >= 0; j++) {

			Tp newF = f[i - j];
			if (j == 2) ++newF.p2;else
			if (j == 3) ++newF.p3;

			if (f[i] < newF) {
				f[i] = newF;
				pr[i] = j;
			}
			if (a[i - j] < a[i - j + 1]) {
				if (state == 1) break;
				state = -1;
			}
			if (a[i - j] > a[i - j + 1]) {
				if (state == -1) break;
				state = 1;
			}
		}
	}
	vector<int> ans;
	for (int i = n; i > 0; i -= pr[i]) {
		ans.push_back(i);
	}
	printf("%d\n", ans.size());
	for (int i = (int)ans.size() - 1; i > 0; i--) printf("%d ", ans[i]);
	if(ans.size()) printf("%d\n", ans[0]);

	return 0;
}
