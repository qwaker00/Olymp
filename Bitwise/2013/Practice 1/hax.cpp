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


#define MOD 1000000007

int C[10010][5050];

LL GetC(int n, int m) {
    if (n - m < m) m = n - m;
    return C[n][m];
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n, k;

    for (int i = 0; i < 10010; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i && j < 5050; ++j) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; 
    }
    cerr << clock() << endl;

    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;

        int k1 = (k + 1) >> 1;
        int k2 = k + 1 - k1;
        cout << (2 * GetC(n - 2, k1 - 1) * GetC(n - 2, k2 - 1)) % MOD << endl;
    } 
    
    return 0;
}
