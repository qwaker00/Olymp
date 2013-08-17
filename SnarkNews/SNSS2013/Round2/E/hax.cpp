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
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    LL ans = 0;
    int x;
    cin >> x;
    while (x > 1) {
        if (x & 1) {
            ans += x - 1;
            x -= 1;
            continue;
        } else {
            ans += x / 2;
            x /= 2;
        }
    }
    cout << ans << endl;
        
    return 0;
}
