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

char revH[256], revV[256], revVH[256];
char a[111], b[111], c[111];
int n1, n2;

bool check() {
		n1 = strlen(a);
		n2 = strlen(b);
		if (n1 != n2) return false;

		c[n1] = 0;
		if (strcmp(b, a) == 0) return true;

		for (int i = 0; i < n1; ++i) c[i] = revH[a[i]];

		if (strcmp(b, c) == 0) return true;

		for (int i = 0; i < n1; ++i) c[n1 - i  -1] = revV[a[i]];

		if (strcmp(b, c) == 0) return true;

		for (int i = 0; i < n1; ++i) c[n1 - i - 1] = revVH[a[i]];

		if (strcmp(b, c) == 0) return true;

		return false;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	revV['d'] = 'b';
	revV['b'] = 'd';
	revV['q'] = 'p';
	revV['p'] = 'q';
	revV['s'] = 'z';
	revV['z'] = 's';
	
	revV['i'] = 'i';
	revV['l'] = 'l';
	revV['m'] = 'm';
	revV['n'] = 'n';
	revV['o'] = 'o';
	revV['u'] = 'u';
	revV['v'] = 'v';
	revV['w'] = 'w';
	revV['x'] = 'x';

	revH['p'] = 'b';
	revH['b'] = 'p';
	revH['w'] = 'm';
	revH['m'] = 'w';
	revH['u'] = 'n';
	revH['n'] = 'u';

	revH['c'] = 'c';

	revVH['s'] = 's';
	revVH['o'] = 'o';
	revVH['x'] = 'x';
	revVH['z'] = 'z';
	                   
	for (int it = 0; it < 33; ++it)
	for (int i = 0; i < 256; ++i) {
		if (!revVH[i] && revV[revH[i]])
			revVH[i] = revV[revH[i]];
		if (!revVH[i] && revH[revV[i]])
			revVH[i] = revH[revV[i]];

		if (!revV[i] && revVH[revH[i]])
			revV[i] = revVH[revH[i]];
		if (!revV[i] && revH[revVH[i]])
			revV[i] = revH[revVH[i]];
  
		if (!revH[i] && revVH[revV[i]])
			revH[i] = revVH[revV[i]];
		if (!revH[i] && revV[revVH[i]])
			revH[i] = revV[revVH[i]];
	}                    
	
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		gets(a);
		gets(b);
		puts(check() ? "YES" : "NO");
	}	
	
	return 0;
}
