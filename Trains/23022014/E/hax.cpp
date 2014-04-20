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

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
        
    int n;
    //cin >> n;

    int iter = 3e7;
    for (int k = 2; k <= 50; ++k) {
        double best = 0;
        double res = 1e9;
        for (int j = 1; j < iter; ++j) {
            double x = PI / k / iter * j;
            double a = sin(x) / sin(k * x);

            if (fabs(a - 1.9) < res) {
                best = x;
                res = fabs(a - 1.9);
            }
        }

        cout.precision(15);
        cout << fixed;
        //cout << k << ": " << best << " (" << res << ")" << endl;
        cout << "angle[" << k << "] = " << best << ";" << endl;
    }

    
    return 0;
}
