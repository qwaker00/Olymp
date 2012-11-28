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


#define N 111111

int a[N], f[N];
int n;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    n++;
    a[n++] = 200000;

    f[0] = 0;
    for (int i = 1; i < n; ++i) {
        f[i] = 2e9;

        int Sum = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (a[j] >= a[i]) Sum += a[j] - a[i];
            else {
                f[i] = min(f[i], f[j] + Sum);
                Sum += a[j];    
            }
        } 

        //cout << i << " " << a[i] << " " << f[i] << endl;
    }

    cout << f[n - 1] << endl;
   
    return 0;
}
