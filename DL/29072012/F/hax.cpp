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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

void Add(int& x) {
	int p = 1, y = x;
	while (y >= 10) {
		p *= 10;
		y /= 10;
	}
	x = (y + 1) * p;
}

char ans[111], s[111];
int l, r;

int main() {
    freopen("minlex.in", "r", stdin);
    freopen("minlex.out", "w", stdout);

    ans[0] = 'z';
    cin >> l >> r;
    while (l <= r) {
    	sprintf(s, "%d", l);
    	if (strcmp(s, ans) < 0) strcpy(ans, s);
    	Add(l);
    }
    cout << ans << endl;

    return 0;
}
