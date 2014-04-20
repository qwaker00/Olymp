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

bool prime(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, y, an = 0, bn = 0, a[33], b[33];
        cin >> x >> y;
        while (x) {
            a[an++] = x & 1;
            x >>= 1;
        }
        while (y) {
            b[bn++] = y & 1;
            y >>= 1;
        }
        while (an > 0 && bn > 0 && a[an - 1] == b[bn - 1]) {
            --bn;
            --an;
        }
        cout << an + bn << endl;
    }
    
    return 0;
}
