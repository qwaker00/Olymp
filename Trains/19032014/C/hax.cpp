#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;

struct Tp {
	int x, y;

	bool operator<(const Tp& t) const {
		return x < t.x || x == t.x && y < t.y;
	}

	bool operator==(const Tp& t) const {
		return x == t.x && y == t.y;
	}
} a[333];

int main() {
	freopen("cottages.in", "r", stdin);
	freopen("cottages.out", "w", stdout);

	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;
	long long ans = 0;	
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int A = a[j].y - a[i].y;
			int B = a[i].x - a[j].x;
			int C = -A * a[i].x - B * a[i].y;
			int c = 0;
			int maxx = max(a[i].x, a[j].x);
			int maxy = max(a[i].y, a[j].y);
			int minx = min(a[i].x, a[j].x);
			int miny = min(a[i].y, a[j].y);
			for (int k = 0; k < n; ++k) {
				if (k == i) ++c;else
				if (k == j) ++c;else
				if (A * a[k].x + B * a[k].y + C == 0) {
					if (a[k].x >= minx && a[k].x <= maxx && a[k].y >= miny && a[k].y <= maxy) {
						c = -1;
						break;
					}
					++c;
				}
			}
			if(c != -1) {
				ans += 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
