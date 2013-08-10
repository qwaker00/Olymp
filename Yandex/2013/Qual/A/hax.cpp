#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

int main() {
    freopen("basketball.in", "r", stdin);
    freopen("basketball.out", "w", stdout);

    int n, l, x, t;
    int r[3] = {0, 0, 0};

    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> t >> x;

        int score;
        if (x == -1) score = 1;else
        if (x > l) score = 3;else score = 2;

        r[t] += score;
    }
    
    cout << r[1] << ":" << r[2] << endl;

    return 0;
}
