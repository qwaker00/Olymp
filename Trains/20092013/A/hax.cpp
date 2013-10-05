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
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);

    LD x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;

    LD b = sqrt(sqr(x1 - x2) + sqr(y1 - y2));
    LD a = sqrt(sqr(x3 - x2) + sqr(y3 - y2));
    LD c = sqrt(sqr(x1 - x3) + sqr(y1 - y3));

    cout.precision(15); cout << fixed;
    cout << (b + c - a) / 2 << endl;
    cout << (b + a - c) / 2 << endl;
    cout << (a + c - b) / 2 << endl;
    
    return 0;
}
