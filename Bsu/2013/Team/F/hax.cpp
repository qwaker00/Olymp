#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int n;
char s[111];
int a[11111], b[11111];

inline void toggle(int* a, int i, int n) {
	a[i] ^= 1;
	a[(i + 1) % n] ^= 1;
	a[(i + n - 1) % n] ^= 1;
}

int Check(int msk) {
	int cnt = 0;

	memcpy(b, a, sizeof(int) * n);
	if (msk & 1) {
		toggle(b, 0, n);
		++cnt;
	}
	if (msk >> 1) {
		toggle(b, 1, n);		
		++cnt;
	}

	for (int i = 2; i < n; ++i) if (b[i - 1] == 0) {
		toggle(b, i, n);
		++cnt;
	}

	for (int i = 0; i < n; ++i) if (!b[i]) return 2e9;
	return cnt;
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s);
		if (strcmp(s, "On") == 0)
			a[i] = 1;else a[i] = 0;
	}    

	int ans = min(min(Check(1), Check(0)), min(Check(2), Check(3)));
	if (ans > 1e9) {
		puts("Epic fail");
	} else {
		cout << ans << endl;
	}

    
    return 0;
}
