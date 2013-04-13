#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define PI 3.1415926535897932384626433832795

int f[111][111];
char s[111];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	
	int T;
	scanf("%d\n", &T);
	for (int __it = 1; __it <= T; ++__it) {
		gets(s);
		int l = strlen(s);


		memset(f, 0, sizeof(f));
		f[0][0] = true;
		for (int i = 0; i < l; ++i)
			for (int j = 0; j <= i; ++j)
				if (f[i][j]) {
					if (s[i] == '(')
						f[i + 1][j + 1] = true;
					if (s[i] == ')' && j > 0)
						f[i + 1][j - 1] = true;
					if (s[i] != ')' && s[i] != '(')
						f[i + 1][j] = true;

					if (i + 1 < l && s[i] == ':' && s[i + 1] == '(')
						f[i + 2][j] = true;
					if (i + 1 < l && s[i] == ':' && s[i + 1] == ')')
						f[i + 2][j] = true;
				}
		printf("Case #%d: %s\n", __it, f[l][0] ? "YES" : "NO");
	}

	
	return 0;
}
