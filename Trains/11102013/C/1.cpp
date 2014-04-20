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

int n, m, k;
int a[22][11];
char ans[22];
string bessy;

bool good(int i, ULL dist) {
    if (i == n) return dist <= k || m - dist <= k;
    return (good(i + 1, (dist * a[i][0] + a[i][1]) % m) && good(i + 1, (dist * a[i][2] + a[i][3]) % m)) ||
           (good(i + 1, (dist * a[i][4] + a[i][5]) % m) && good(i + 1, (dist * a[i][6] + a[i][7]) % m));
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n >> m >> k;
    cin >> bessy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j) cin >> a[i][j];
    }
    
    ULL dist = 0;
    for (int i = 0; i < n; ++i) {
        if (good(i + 1, (dist * a[i][4] + a[i][5]) % m) && 
            good(i + 1, (dist * a[i][6] + a[i][7]) % m)
        ) {
            ans[i] = 'B';
        } else {
            ans[i] = 'T';
        }

        if (ans[i] == 'T') {
            if (bessy[i] == 'T')
                dist = (dist * a[i][0] + a[i][1]) % m;
            else
                dist = (dist * a[i][2] + a[i][3]) % m;                
        } else {
            if (bessy[i] == 'T')
                dist = (dist * a[i][4] + a[i][5]) % m;
            else
                dist = (dist * a[i][6] + a[i][7]) % m;                
        }
    }
    puts(ans);

    return 0;
}