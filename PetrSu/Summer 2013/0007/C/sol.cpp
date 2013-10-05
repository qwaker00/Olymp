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

typedef long long LL;
typedef long double LD;
const LD PI = acos(-1.);
using namespace std;

int n;
LL R, r;
LD als;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	scanf("%d%I64d", &n, &R);
	LD s1 = 0, s2 = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &r);
		als = LD(r) / R;
		s1 += als;
		s2 += als * als;
	}
	LD ans = s1 * s1 - s2;
//	for (int i = 0; i < n; ++i)
//		for (int j = i + 1; j < n; ++j) {
//			ans += 2 * als[j] * als[i];
//		}
    cout.precision(14); cout << fixed;
	cout << ans << endl;
	
	return 0;
}
