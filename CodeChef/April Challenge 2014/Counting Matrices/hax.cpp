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

const int N = 2500;
int c[N * N + 11];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int NN = N * N;
    for (int i = 1; i <= NN; ++i)
        for (int j = 1; i * j <= NN; ++j)
            ++c[i * j];
    for (int i = 1; i <= N * N; ++i)
        c[i] += c[i - 1];
    cerr << clock() << endl;

    for (int n = 3; n <= N; ++n) {
        LL ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += c[i * (n - i) - 1];
        cout << "\"" << ans << "\",";
    }

    return 0;
}
