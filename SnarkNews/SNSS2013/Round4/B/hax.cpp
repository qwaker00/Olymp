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

#define M 1000000007
#define GET(x, i) (((x)>>i)&1)

int f[11111][16], n;

void Add(int x, int & y) {
    y = (y + x) % M;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n;
    f[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 16; ++j) if (f[i][j]) {
            if (GET(j, 2) == 0 && i)
                Add(f[i][j], f[i+1][j | 1]);
            if (GET(j, 3) == 0)
                Add(f[i][j], f[i+1][j | 2]);
            if (GET(j, 0) == 1)
                Add(f[i][j], f[i+1][j | 4]);
            if (GET(j, 1) == 1)
                Add(f[i][j], f[i+1][j | 8]);
        }
    }

    cout << f[n][15] << endl;
    
    return 0;
}
