#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

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
    
    ULL L, R, X, A = 0;
    cin >> L >> R >> X;
    for (int i = 63; i >= 0; --i) {
        ULL b = 1 - (((1ull << i) & X) > 0);
        if ( ((A >> i) | b) <= (R >> i) && ((A >> i) | b) >= (L >> i) ) {
            A |= b << i;
        } else {
            A |= (1 - b) << i;
        }
    }
    cout << A << endl;
    
    return 0;
}
