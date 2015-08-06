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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    int T;
    cin >> T;
    while (T--) {
        LL n;
        cin >> n;
        cout << ( (n * (n - 1) + n * (n - 1) * (n - 2)) * 2 + (n * (n - 1) * (n - 2) + n * (n - 1) * (n - 2) * (n - 3)) * 2 + n * (n - 1) * (n - 2) ) << endl;
    }

    return 0;
}

