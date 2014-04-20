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
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
    ULL x, y, z;
    cin >> x >> y >> z;
    ULL a = 0, b = 1; // a * z + b
    while (y--) {
        a = a * x + (b * x) / z;
        b = (b * x) % z;
    }
    cout.precision(12);
    cout << fixed;
    if (a + LD(b) / z < 1000)
        cout << a + LD(b) / z << endl;
    else {
        stringstream s;
        s.precision(12);
        s << fixed;
        s << LD(b) / z;
        char ch;
        string st;
        s >> ch;
        s >> st;
        cout << a << st << endl;
    }
    return 0;
}
