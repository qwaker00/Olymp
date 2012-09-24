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


int a[111][111], n, m, ansv[111], ansh[111], sumv[111], sumh[111];
bool good;

int main() {
    //freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            sumv[i] += a[i][j];
            sumh[j] += a[i][j];
        }
    }

    good = false;
    while (!good) {
        good = true;
        for (int i = 0; i < n; i++) {
            if (sumv[i] < 0) {
                good = false;
                sumv[i] = -sumv[i];
                ansv[i] ^= 1;
                for (int j = 0; j < m; ++j) {
                    sumh[j] += -a[i][j] - a[i][j];
                    a[i][j] = -a[i][j];
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (sumh[j] < 0) {
                good = false;
               sumh[j] = -sumh[j];
               ansh[j] ^= 1;
                for (int i = 0; i < n; ++i) {
                    sumv[i] += -a[i][j] - a[i][j];
                    a[i][j] = -a[i][j];
                }
            }
        }
    }
    int aa = 0;
    aa = 0;
    for (int i = 0; i < n; i++) if (ansv[i]) aa++;
    cout << aa << endl;
    for (int i = 0; i < n; i++) if (ansv[i]) cout << i + 1 << " ";
    cout << endl;
    aa = 0;
    for (int i = 0; i < m; i++) if (ansh[i]) aa++;
    cout << aa << endl;
    for (int i = 0; i < m; i++) if (ansh[i]) cout << i + 1 << " ";
    cout << endl;


    
    return 0;
}
