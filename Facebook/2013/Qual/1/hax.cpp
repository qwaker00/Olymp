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

int c[33];
char s[11111];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	
	int n;
	scanf("%d\n", &n);
	for (int it = 0; it < n; ++it) {
		gets(s);
		int l = strlen(s);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < l; ++i) {
			if (s[i] >= 'a' && s[i] <= 'z')
				c[s[i] - 'a']++;
			if (s[i] >= 'A' && s[i] <= 'Z')
				c[s[i] - 'A']++;
		}
		sort(c, c + 26);
		int ans = 0;
		for (int i = 25; i >= 0; i--) {
			ans += c[i] * (i + 1);
		}
		cout << "Case #" << (it + 1) << ": " << ans << endl;
	}
	
	return 0;
}
