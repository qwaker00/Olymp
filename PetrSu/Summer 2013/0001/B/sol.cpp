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

const int N = 200222;
char w[N];
int r[N];

int main() {
	freopen("bad.in", "r", stdin);
	freopen("bad.out", "w", stdout);

	ll ans = 0;
	gets(w);
	int n = strlen(w);

	for (int i = 0; i < n; ++i) {
		if (w[i] == '1') ans += 4;
	}
	r[n - 1] = -1;
	for (int i = n - 2; i >= 0; --i) 
		if (w[i + 1] == '1') r[i] = i + 1;
		else r[i] = r[i + 1];

	ll cans = 1e10;
	for (int i = 0; i < n; ++i) {
		ll cand = min(i * 14 + (n - r[i]) * 7, i * 7 + (n - r[i]) * 14);
		if (r[i] == -1) cand = i * 7;
		cans = min(cans, cand);
	}

	cout << ans + cans << endl;

	
	return 0;
}
