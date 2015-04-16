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

int a[11111];
int pos[11111];

inline void make_swap(vector< pair<int, int> >& ans, int* a, int l, int len) {
	ans.push_back(make_pair(l + 1, l + len + len));
	for (int i = 0; i < len; ++i) {
		swap(a[l + i], a[l + i + len]);
		pos[a[l + i]] = l + i;
		pos[a[l + i + len]] = l + i + len;
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		vector< pair<int, int> > ans;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			--a[i];
			pos[a[i]] = i;
		}
		for (int i = 0; i < n; ++i) {
			if (pos[i] == i) continue;
			if (pos[i] + pos[i] - i > n) {
				if (((n - i) & 1) == 1 && pos[i] == n - 1) {
					make_swap(ans, a, n - 2, 1);
				}
				if (pos[i] != i && pos[i] + pos[i] - i > n) {
					make_swap(ans, a, i, (n - i) >> 1);
				}
			}
			if (pos[i] != i) {
				assert(pos[i] + pos[i] - i <= n);
				make_swap(ans, a, i, pos[i] - i);
			}
			assert(pos[i] == i);
		}
		for (int i = 0; i < n; ++i)
			assert(pos[i] == i);
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}

    return 0;
}
