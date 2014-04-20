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

char s[111111];
int c[256];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d\n", &T);
	while (T--) {
		gets(s);
		int n = strlen(s);

		memset(c, 0, sizeof(c));

		bool good = true;
		for (int i = 0; i < n; ++i) {
			if (++c[s[i]] == 3) {
				c[s[i]] = 0;
				++i;
				if (s[i] != s[i - 1]) {
					good = false;
					break;
				}
			}
		}

		puts(good ? "OK" : "FAKE");
	}
	

    return 0;
}
