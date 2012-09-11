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
int t, c1, c2, a1, a2;

int main() {
    freopen("toys.in", "r", stdin);
    freopen("toys.out", "w", stdout);

    cin >> t >> c1 >> c2 >> a1 >> a2;
    if (c1 > c2) {
    	swap(c1, c2);
    	swap(a1, a2);
    }

    cout << max(t * (a1 + a2), c1 * (a1 - 1) + c2 * a2 + t) + c1 + t << endl;

    return 0;
}
