#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

int p1[55555], p2[55555];
char s1[55555][22], s2[55555][22], s[22];
int n, ans1[55555], ans2[55555];

bool Up(int x, int y) {
	return strcmp(s1[x], s1[y]) < 0;
}
bool Down(int x, int y) {
	return strcmp(s2[x], s2[y]) < 0;
}

int main() {
    freopen("scramble.in", "r", stdin);
    freopen("scramble.out", "w", stdout);

    scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(s);
		strcpy(s1[i], s);
		strcpy(s2[i], s);
		sort(s1[i], s1[i] + strlen(s1[i]));
		sort(s2[i], s2[i] + strlen(s2[i]), greater<char>());
		p1[i] = i;
		p2[i] = i;
	}
	sort(p1, p1 + n, Up);
	sort(p2, p2 + n, Down);

	for (int i = 0; i < n; ++i) {
		strcpy(s2[n], s1[i]);
		ans1[i] = lower_bound(p2, p2 + n, n, Down) - p2 + 1;
	}
	for (int i = 0; i < n; ++i) {
		strcpy(s1[n], s2[i]);
		ans2[i] = upper_bound(p1, p1 + n, n, Up) - p1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", ans1[i], ans2[i]);
	}
    
    return 0;
}
