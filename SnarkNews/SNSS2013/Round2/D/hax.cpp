#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

int n, m, k;
char art[111];
char s[111];
int a[111][111];
int anss = 0;
int anst = 1;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d%d\n", &n, &m, &k);
    scanf("%s\n", art);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        for (int j = 1; j <= m; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + (strchr(art, s[j - 1]) != 0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int ii = i + k - 1; ii <= n; ++ii)
                for (int jj = j + k - 1; jj <= m; ++jj) {
                    int ss = a[ii][jj] - a[ii][j - 1] - a[i - 1][jj] + a[i - 1][j - 1];
                    int tt = (ii - i + 1) * (jj - j + 1);
                    if (ss * anst > anss * tt || (ss * anst == anss * tt && tt > anst)) {
                        anss = ss;
                        anst = tt;
                    }
                }
        }
    }
    cout << anss << "/" << anst << endl;    
    return 0;
}

