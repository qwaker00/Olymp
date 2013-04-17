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

#define N 111111

int x, y, n, m;
int d[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        d[x]++;
        d[y]++;        
    }    

    int oneC = 0;
    int twoC = 0;
    int noneC = 0;
    for (int i = 1; i <= n; ++i) oneC += d[i] == 1, twoC += d[i] == 2, noneC += d[i] == n - 1;
    if (oneC == 2 && twoC == n - 2) {
        puts("bus topology");
    } else
    if (twoC == n) {
        puts("ring topology");
    } else
    if (oneC == n - 1 && noneC == 1) {
        puts("star topology");
    } else {
        puts("unknown topology");
    }
    
    return 0;
}
