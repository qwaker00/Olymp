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

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char s[211111], a[211111];
int l;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	gets(s);
	l = strlen(s);
	a[l - 1] = s[l - 1];
	for (int i = l - 2; i >= 0; i--) {
		a[i] = max(a[i + 1], s[i]);
	}
	for (int i = 0; i < l; i++) {
		if (s[i] == a[i]) {
			putchar(a[i]);
		}
	}
	puts("");
	
	return 0;
}
