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

int n, t;
LD f[555][555], p[555], q[555];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];


    for (int i = 0; i <= t; i++) f[n][i] = 1.;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = t; j >= 0; j--) {
            LD res1 = p[i] * f[i + 1][j + 1];
            LD res2 = (1. - p[i]) * q[i] * f[i][j + 2] + p[i] * f[i + 1][j + 2]; 
            f[i][j] = max(res1, res2);
        }
    }
    cout.precision(15);
    cout << fixed << f[0][0] << endl; 
    
    return 0;
}
