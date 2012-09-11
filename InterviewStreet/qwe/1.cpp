#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	int ans = 0;
	for (int i = 1; i < 32328; i++) {
		++ans;
		for (int j = 1; j < i; j++) {
			if (__gcd(i, j) == 1) ans += 2;
		}
		cerr << i << endl;
	}
	cout << ans << endl;

	return 0;
}
