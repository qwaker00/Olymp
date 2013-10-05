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

int f[3333][3333];
char s[3333][3333];
int n, m;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    scanf("%d%d\n", &n, &m);
    for (int i =0 ; i < n; ++i) {
        gets(s[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (s[i][j]  != '#') {
            if (i == 0 && j == 0) f[i][j] = 1;else {
                f[i][j] = 0;
                if (i > 0) f[i][j] += f[i - 1][j];
                if (j > 0) f[i][j] += f[i][j - 1];
                if (i > 0 && j > 0) f[i][j] += f[i - 1][j - 1];
            }            
        }
    }
    cout << f[n][m] << endl;

    return 0;
}
