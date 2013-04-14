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

inline int myabs(int x) {
    if (x < 0) return -x;
    return x;
}


int main() {
    freopen("right-turn-only.in", "r", stdin);
    freopen("right-turn-only.out", "w", stdout);
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);

        if (x == 0 && y == 0) {
            puts("0");
        }else
        if (y > 0 && x >= 0) {
            printf("%d\n", abs(x) + abs(y));
        } else if (x >= 1) {
            printf("%d\n", abs(x) + abs(y) + 2);
        } else {
            printf("%d\n", abs(x) + abs(y) + 4);
        }
    }
    
    return 0;
}
