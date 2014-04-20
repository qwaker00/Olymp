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

char s[1111111];

char c[256];


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	int ans = 0;

	c['A'] = c['D'] = c['O'] = c['P'] = c['Q'] = c['R'] = 1;
	c['B'] = 2;
    
	gets(s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i)
		ans += c[s[i]];
	cout << ans << endl;
    
    return 0;
}
