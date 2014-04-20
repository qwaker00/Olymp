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

int id[11][11];
int start[11][11];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int first = 1;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        if (!first) puts("");
        first = 0;

        int cnt = 0;
        memset(id, 0, sizeof(id));
        memset(start, 0, sizeof(start));
        for (int i = 0; i < n; ++i) {
            int k, py = 0, x, y;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                ++cnt;
                while (id[i][py]) ++py;

                cin >> x >> y;
                for (int ii = 0; ii < x; ++ii)
                for (int jj = 0; jj < y; ++jj)
                    id[i + ii][py + jj] = cnt;
                start[i][py] = true;
            }
        }
        int width = 0;
        while (id[0][width]) ++width;

        for (int i = 0; i < width; ++i) printf(" --"); puts(" ");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < width; ++j) {
                if (j == 0 || id[i][j - 1] != id[i][j]) {
                    putchar('|');
                } else
                    putchar(' ');
                if (start[i][j]) {
                    putchar(i + '1');
                    putchar(j + '1');
                } else {
                    putchar(' ');
                    putchar(' ');
                }
            }
            puts("|");
            for (int j = 0; j < width; ++j)
                if (i == n - 1 || id[i][j] != id[i + 1][j])
                    printf(" --");
                else
                    printf("   ");
            puts(" ");
        }
    }
    
    return 0;
}
 