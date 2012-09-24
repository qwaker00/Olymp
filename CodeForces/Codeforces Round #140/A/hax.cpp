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

    LL n, m; 
    cin >> n >> m;
    LL a = 3, res = 1;
    while (n) {
        if (n&1) res = (res * a) % m;
        n >>= 1;
        a = (a * a) % m;
    }
    if (res == 0) res += m;
    cout << res - 1 << endl;
    
    return 0;
}
