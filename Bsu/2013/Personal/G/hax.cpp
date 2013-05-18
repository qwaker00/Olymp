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


int main() {
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    
    LL ans =0 ;
    int n, x;
	scanf("%d", &n);
	for (int i  = 0; i < n; ++i) {
		for (int j =0 ; j < n; ++j) {
			scanf("%d", &x);
			if (x == 0) x = n * n;
			--x;

			ans += abs(i - (x/n)) + abs(j - (x%n));
		}
	}
	cout << ans << endl;
    
    return 0;
}

