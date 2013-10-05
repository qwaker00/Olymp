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

bool e[444][444];
int idi[444], idj[444], k;
int a[6][444];
int ans[444];
int xy[444];

int main() {
    freopen("eq.in", "r", stdin);
    freopen("eq.out", "w", stdout);

    for (int i = 0; i < 6; ++i) {
        scanf("%d", &k);
        for (int j = 0; j <= k; ++j) {
            scanf("%d", &a[i][k - j]);
        }
    }
    for (int i = 0; i < 202; ++i) {
        for (int j = i; j >= 0 && i - j < 101; --j) e[i][i - j] = a[0][j];
        for (int j = i; j >= 0 && i - j < 101; --j) e[i][i - j + 101] = a[1][j];
        e[i][202] = a[2][i];
    }
    for (int i = 0; i < 202; ++i) {
        for (int j = i; j >= 0 && i - j < 101; --j) e[i + 202][i - j] = a[3][j];
        for (int j = i; j >= 0 && i - j < 101; --j) e[i + 202][i - j + 101] = a[4][j];
        e[i + 202][202] = a[5][i];
    }

    for (int i = 0; i < 202; ++i) {
        idj[i] = i;
    }
    for (int i = 0; i < 202; ++i) {
        if (e[i][i] == 0) {
            bool found = 0;
            for (int j = i + 1; j < 404; ++j)
                if (e[j][i]) {
                    for (int k = i; k <= 202; ++k) {
                        swap(e[i][k], e[j][k]);
                    }
                    found = 1;
                    break;
                }
            if (!found) {
                for (int j = i + 1; j < 202; ++j)
                        if (e[i][j]) {
                        for (int k = 0; k < 404; ++k) {
                            swap(e[k][i], e[k][j]);
                        }
                        swap(idj[i], idj[j]);
                        found = 1;
                        break;
                    }
                if (!found) {
                    if (e[i][202]) {
                        cerr << i << endl;
                        puts("No solution");
                        exit(0);
                    } else continue;
                }
            }
        }
        for (int j = i + 1; j < 404; ++j) {
            if (e[j][i])
                for (int k = i; k <= 202; ++k) {
                    e[j][k] ^= e[i][k];
                }
        }
    }
    for (int i = 202 - 1; i >= 0; --i) {
        bool r = e[i][202];
        for (int j = i + 1; j < 202; ++j) r ^= (e[i][j] & ans[j]);
        ans[i] = r;
    }
    for (int i = 0; i < 404; ++i) {
        int r = e[i][202];
        for (int j = 0; j < 202; ++j) {
            r ^= e[i][j] & ans[j];
        }
        if (r != 0) {
            puts("No solution");
            exit(0);
        }
    }

    for (int i = 0; i < 202; ++i) xy[ idj[i] ] = ans[i];
    int* x = xy;
    int* y = xy + 101;
    int lx = 101 - 1;
    int ly = 101 - 1;
    while (lx >= 0 && x[lx] == 0) --lx;
    while (ly >= 0 && y[ly] == 0) --ly;

    cout << lx;
    for (int i = 0; i <= lx; ++i) cout << ' '  << x[lx - i];
    cout << '\n';

    cout << ly;
    for (int i = 0; i <= ly; ++i) cout << ' '  << y[ly - i];
    cout << '\n';

    return 0;
}
