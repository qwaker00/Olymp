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
    
    for (int r = 2; r <= 100; ++r) {
        int f1 = 0;
        int f2 = 1;
        int it = 0;
        while (true) {
            ++it;
            int f3 = (f2 + f1) % r;
            f1 = f2;
            f2 = f3;
            cout << f3 << " ";

            if (f1 == 0 && f2 == 1) break;
        }
        cout << endl;
        cout << r << ": " << it << endl;
    }    
    
    return 0;
}
