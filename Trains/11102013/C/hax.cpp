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
#include <assert.h>

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

#define Move(D, FJ, BS, A, M) ((D * A[((FJ=='B')<<2) + ((BS=='B')<<1)] + A[((FJ=='B')<<2) + ((BS=='B')<<1) + 1])%M)

bool good(int i, ULL dist) {
    if (i == n) return (int)dist <= k || m - (int)dist <= k;
    return (good(i + 1, Move(dist, 'T', 'B', a[i], m)) && good(i + 1, Move(dist, 'T', 'T', a[i], m))) ||
           (good(i + 1, Move(dist, 'B', 'B', a[i], m)) && good(i + 1, Move(dist, 'B', 'T', a[i], m)));
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n >> m >> k;
    cin >> bessy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 8; ++j)
            cin >> a[i][j];
    }
    
    ULL dist = 0;
    for (int i = 0; i < n; ++i) {
        if (good(i + 1, Move(dist, 'B', 'T', a[i], m)) && 
            good(i + 1, Move(dist, 'B', 'B', a[i], m))
        ) {
            ans[i] = 'B';
        } else {
            ans[i] = 'T';
        }
        dist = Move(dist, ans[i], bessy[i], a[i], m);
    }
    assert( (int)dist <= k || m - (int)dist <= k );
    puts(ans);

    return 0;
}
