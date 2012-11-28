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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define D 111

int f[D][D][D+D];
int d;
char s[D];
int n, ans;


inline void Max(int& x, int y) {
    if (x < y) x = y;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d\n", &d);
    gets(s);
    n = strlen(s);

    if (n == 1) {
        if (d > 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    ans = 0;
    memset(f, -1, sizeof(f));
    f[0][1][D] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n + 1; j++) {
            for (int k = -d; k <= d; k++) if (f[i][j][k + D] != -1) {
                ans = max(ans, f[i][j][k + D]);
                if (i < n) {
                    int newi = j;
                    int newj = j + 1;

                    int newd = k + (s[i] == 'M') * 2 - 1;

                    if (newd <= d && newd >= -d) {
                        Max(f[newi][newj][newd + D], f[i][j][k + D] + 1);
                    }
                }

                if (j < n) {
                    int newi = i;
                    int newj = j + 1;
                    int newd = k + (s[j] == 'M') * 2 - 1;

                    if (newd <= d && newd >= -d) {
                        Max(f[newi][newj][newd + D], f[i][j][k + D] + 1);
                    }                 
                }

            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
