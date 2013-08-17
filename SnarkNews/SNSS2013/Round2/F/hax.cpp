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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n == 1 && m == 1) {
        cout << 0 << endl;
    } else 
    if (n == 1 || m == 1) {
        if (m == 1) {swap(p, q); swap(n, m);}
        cout << 2*(m - 1) << endl;
    } else {
        if ((n & 1) && (m & 1))
            cout << n * m + 1 << endl;else
            cout << n * m << endl;
    }
    
    return 0;
}
