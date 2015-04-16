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

const int N = 300111;
int sufmas[N], where[N];
char w[N], s[N+N];
int cls[N];
int md[N+N+N];

struct cell {
	int c1, c2;
	int pos;

	bool operator <(const cell& A) const {
		if (c1 != A.c1) return c1 < A.c1;
		return c2 < A.c2;
	}
} a[N];

int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
	
    int n;
    scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x); --x;
		where[x] = i;
		sufmas[i] = x;
	}

	int who = -1;
	for (int i = 0; i < n; ++i) {
		if (sufmas[i] != n - i - 1) {
			who = n - i - 1;
			break;
		}
	}

	if (who == -1) {
		for (int i = 0; i < n; ++i) putchar('0');
		puts("");
		return 0;
	}

	bool zero = true;
	for (int i = 0; i < n; ++i) {
		if (sufmas[i] == who) zero = false;
		if (zero) w[ sufmas[i] ] = '0';
		else w[ sufmas[i] ] = '1';
	} 
	for (int i = 0; i < n; ++i) s[i] = s[n + i] = w[i];
	s[n++] = 0;

	int lim = 1;
	while ((1 << lim) < n) ++lim;
	for (int i = 0; i < n; ++i) md[i] = md[n + i] = md[n + n + i] = i;

	for (int i = 0; i < n; ++i) 
		if (s[i] == '0') cls[i] = 1;
		else if (s[i] == '1') cls[i] = 2;
		else cls[i] = 0;

	for (int l = 1; l <= lim; ++l) {
		int shift = (1 << (l - 1));
		for (int i = 0; i < n; ++i) {
			a[i].c1 = cls[i];
			a[i].c2 = cls[md[i + shift]];
			a[i].pos = i;
		}
		sort(a, a + n);

		int cnum = 1;
		cls[a[0].pos] = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i].c1 != a[i - 1].c1 || a[i].c2 != a[i - 1].c2) ++cnum;
			cls[a[i].pos] = cnum - 1;
		}
	}

	for (int i = 1; i < n; ++i)
		if (sufmas[i - 1] != a[i].pos) {
			puts("Error");
			return 0;		
		}

	puts(w);

    return 0;
}
