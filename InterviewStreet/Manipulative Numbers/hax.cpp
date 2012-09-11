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

unsigned a[111111], b[111111];
int n;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 31; i >= 0; i--) {
		for (int j = 0; j < n; j++) b[j] = a[j] >> i;
		sort(b, b + n);
		unsigned x = b[0];
		int cnt = 1, maxcnt = 1;
		for (int j = 1; j < n; j++) {
			if (b[j] == x) {
				++cnt;
				if (cnt > maxcnt) maxcnt = cnt;
			} else {
				cnt = 1;
				x = b[j];
			}
		} 
		if (maxcnt <= n - maxcnt) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
	return 0;
}
