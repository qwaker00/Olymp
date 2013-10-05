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

int r(int a, int b) {
    int s = (rand() << 15) + rand();
    return a + s % (b - a + 1);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    srand(time(0));
    const int n = 200000;
    const int m = 200000;
    vector<int> w(n), ids(n);
    for (int i = 0; i < n; ++i) w[i] = r(-10000, 10000); 
    for (int i = 0; i < n; ++i) ids[i] = i;
    random_shuffle(ids.begin(), ids.end());
    vector< pair<int, int> > e;
    for (int i = 1; i < n; ++i) {
        if (r(0, 1) == 0)
            e.push_back(make_pair(ids[i], ids[r(0, i - 1)]));else
            e.push_back(make_pair(ids[r(0, i - 1)], ids[i]));
    }
    random_shuffle(e.begin(), e.end());

    printf("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) printf("%d ", w[i]);
    puts("");
    for (int i = 0; i < e.size(); ++i) {
        printf("%d %d\n", e[i].first + 1, e[i].second + 1);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d %d %d %d\n", r(1, 2), r(1, n), r(1, n), r(-10000, 10000));
    }
    
    return 0;
}
