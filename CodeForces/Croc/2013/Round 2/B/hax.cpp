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

#define N 611111

int n, k, m;
int a[111][111], nx[111][111], ny[111][111], FX, FY;
int ans = 0;

void Calc(int x, int y, int mask, int nmask) {
    if (x == FX && y == FY) {
      /*  for (int i =0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cerr << a[i][j] << " ";
            cerr << endl;
        }
        cerr << endl;
      */
        ++ans;
        return;
    }
    if (a[x][y] != -1) {
        if (mask & (1 << a[x][y])) {
            if (nx[x][y] == x + 1 && ny[x][y] == y - 1)
                Calc(nx[x][y], ny[x][y], mask, nmask | (1 << a[x][y]));else
                Calc(nx[x][y], ny[x][y], mask ^ (nmask | (1 << a[x][y])), 0);
        }
        else
            return;
    } else {
        for (int i = 0; i < k; ++i)
            if (mask & (1 << i)) {
//                a[x][y] = i;
                if (nx[x][y] == x + 1 && ny[x][y] == y - 1)
                    Calc(nx[x][y], ny[x][y], mask, nmask | (1 << i));else
                    Calc(nx[x][y], ny[x][y], mask ^ (nmask | (1 << i)), 0);
            }
                
    }
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);
    if (n + m - 1 > k) {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            --a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n && j - 1 >= 0) {
                nx[i][j] = i + 1;
                ny[i][j] = j - 1;
            } else {
                int tx = i + j + 1;

                for (int ii = 0, f = 0; !f && ii < n; ++ii)
                    for (int jj = 0; !f && jj < m; ++jj) if (ii + jj == tx) {
                        nx[i][j] = ii;
                        ny[i][j] = jj;
                        f = 1;
                        break;
                    }
            }
        }
    }
    FX = nx[n - 1][m - 1] = n + 1;
    FY = ny[n - 1][m - 1] = m + 1;

    Calc(0, 0, (1 << k) - 1, 0);
    cout << ans << endl;
    
    return 0;
}

