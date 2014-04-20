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

struct Tp {
    LL A, B, C;
} a[1111];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[i].A = y2 - y1;
        a[i].B = x1 - x2;
        a[i].C = -x1 * a[i].A - y1 * a[i].B;
    }
    cout << 0 << endl;
    
    return 0;
}
