#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 200011;
int a[N], p[N], x, n;

bool check(int place) {
	int got = a[0] + p[place];

	int need = x;
	for (int i = 0; i < n; ++i) {
		if (i == place) continue;
		if (p[i] + a[need] <= got) return true;
		--need;
		if (need == 0) break; 
	}

	return need > 0;
}

int main() {
	freopen("hop.in", "r", stdin);
	freopen("hop.out", "w", stdout);
	
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
	}
	sort(a + 1, a + n);
	reverse(a + 1, a + n);

	if (!check(0)) {
		puts("-1");
		return 0;
	}

	int l = 0, r = n - 1;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	cout << l + 1 << endl;
	
	return 0;
}
