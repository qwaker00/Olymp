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


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	char s[11111];
	int c1[128], c2[128];
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
    scanf("%d\n", &T);
    while (T--) {
    	gets(s);
    	for (int i = 0; s[i]; ++i) ++c1[s[i]];
    	gets(s);
    	for (int i = 0; s[i]; ++i) ++c2[s[i]];
    	int ans = 0;
    	for (int i = '0'; i <= 'z'; ++i) {
    		ans += min(c1[i], c2[i]);
    		c1[i] = c2[i] = 0;
    	}
    	printf("%d\n", ans);
    }

    return 0;
}
