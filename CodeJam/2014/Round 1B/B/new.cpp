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

LL f[33][2][2][2];


LL solve() {
    int A, B, K;
    cin >> A >> B >> K;

    memset(f, 0, sizeof(f));
    f[31][1][1][1] = 1;
    for (int l = 31; l > 0; --l) {
        int da = (A & (1 << (l - 1))) > 0;
        int db = (B & (1 << (l - 1))) > 0;
        int dk = (K & (1 << (l - 1))) > 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) if (f[l][i][j][k]) {
                    for (int d1 = 0; d1 < 2; ++d1) {
                        for (int d2 = 0; d2 < 2; ++d2) {
                            int d3 = d1 & d2;
                            if (i && d1 > da) continue;
                            if (j && d2 > db) continue;
                            if (k && d3 > dk) continue;
                            f[l - 1][i && d1 == da][j && d2 == db][k && d3 == dk] += f[l][i][j][k];
                        }
                    }
                }
            }
        }
    }

    return f[0][0][0][0];
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int it = 1; it <= T; ++it) {
        cout << "Case #" << it << ": " << solve() << endl;
    }    
    
    return 0;
}
