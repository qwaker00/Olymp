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

char a[1111], b[1111], cnt[1111];
int la, lb;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);    

    int n, m, c1 = 0, c2 = 0;
    gets(a);
    n = strlen(a);
    for (int k = 0; k < n; ++k) c1 += (a[k] == '1');

    gets(b);    
    m = strlen(b);
    for (int k = 0; k < m; ++k) c2 += (b[k] == '1');

    if (c1 + (c1&1) >= c2) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}

                     