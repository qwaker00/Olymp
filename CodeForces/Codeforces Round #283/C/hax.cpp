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

const int N = 111111;
struct Tp {
	int l, r, k, i;
	bool operator<(const Tp& t) const {
		return l < t.l || (l == t.l && r < t.r);
	}
} p[N], a[N];
int ans[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &p[i].l, &p[i].r);
		p[i].k = i;
	}
	sort(p, p + n);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].k);
		a[i].i = i;
	}
	sort(a, a + m);
	map< pair<int, int>, int> s;
	for (int i = 0, j = 0; i < n; ++i) {
		while (j < m && a[j].l <= p[i].l) {
			s[ make_pair(a[j].r, a[j].i) ] = a[j].k;
			++j;
		}
		auto it = s.lower_bound( make_pair(p[i].r, -1) );
		if (it == s.end()) {
			puts("NO");
			return 0;
		}
		ans[ p[i].k ] = it->first.second;
		if ( --(it->second) == 0) {
			s.erase(it);
		}
	}
	puts("YES");
	for (int i =0 ; i < n; ++i) printf("%d ", ans[i] + 1);
	puts("");
    
    return 0;
}
