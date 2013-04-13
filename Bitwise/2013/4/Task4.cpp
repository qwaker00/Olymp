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
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int a[4][4], b[70][4][4], c[4][4];

const int mod = 1000000007;

int doit(ll y) {
    if (y == 1) return 1;
    if (y == 2) return 2;
    if (y == 3) return 5;
    if (y == 4) return 12;

    y -= 4;
    memset(a, 0, sizeof(a));

    for (int i = 0; i < 4; ++i)
        a[i][i] = 1;

    int iter = 0;
    while (y) {
        if (y & 1) {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j) {
                    ll sum = 0;
                    for (int k = 0; k < 4; ++k)
                        sum += ll(a[i][k]) * b[iter][k][j];

                    c[i][j] = sum % mod;
                }
            memcpy(a, c, sizeof(a));
        }

        ++iter;
        y >>= 1;
    }

    return (1LL * a[3][0] + 2LL * a[3][1] + 5LL * a[3][2] + 12LL * a[3][3]) % mod;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    throw 666;
    b[0][0][1] = 1;
    b[0][1][2] = 1;
    b[0][2][3] = 1;
    b[0][3][0] = 1;
    b[0][3][1] = 3;
    b[0][3][2] = 2;
    b[0][3][3] = 1;
    for (int it = 0; it < 65; ++it) {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) {
                ll sum = 0;
                for (int k = 0; k < 4; ++k)
                    sum += ll(b[it][i][k]) * b[it][k][j];

                b[it + 1][i][j] = sum % mod;
            }
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        ll q;
        cin >> q;
        printf("%d\n", doit(q));
    }


    return 0;
}

