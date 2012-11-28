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


int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    LD R, h1, h2, x;
    cin >> R >> h1 >> h2 >> x;
    cout.precision(20);
                                 
    LD old = (PI * R * sqrtl(R*R + h2 * h2));
    LD nw = 0.5 * x * sqrtl(R * R + h2*h2);


    cout << fixed <<  (nw + h1 * x) / (2. * old + 2. * PI * R * h1) * 100. << endl;

    
    return 0;
}
