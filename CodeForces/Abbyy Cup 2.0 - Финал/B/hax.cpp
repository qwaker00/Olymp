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

struct Tp {
	int l, r, i;


	bool operator<(const Tp& B)const{
		return l < B.l || l == B.l && r > B.r;
	}
} a[555555];
int n, x, cnt, start, curmax, pos[555555];
    
int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		a[i].r = i;
		a[i].l = i - x;
		a[i].i = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) pos[a[i].i] = i;

	LL ans = 0;
	for (int it = 0; it < n; it++) {
		start = -it;
		curmax = -2e9;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i].l > start) {
				++cnt;
				start = curmax;
				curmax = a[i].r;
				if (curmax >= n - it - 1) break;
			} else { 	
				if (a[i].r > curmax) curmax = a[i].r;
				if (curmax >= n - it - 1) break;
			}
		}
//		if (start != n - 1) ++cnt;
		++cnt;

		int cc = pos[n - it - 1];
		a[cc].l -= n;
		a[cc].r -= n;
		while (cc > 0 && a[cc].l < a[cc - 1].l) {	
			swap(pos[a[cc].i], pos[a[cc - 1].i]);
			swap(a[cc], a[cc - 1]);
			cc--;			
		}
		ans += cnt;
	}
	cout << ans << endl;

	return 0;
}
