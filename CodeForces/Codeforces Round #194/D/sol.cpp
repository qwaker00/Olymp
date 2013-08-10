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

pair<int,int> a[1010][1010];
int IT = 0, was[1010][1010], n, m;

bool Can(int thres) {
    ++IT;
    for (int i = 0; i < n; ++i) {
        int start = lower_bound(a[i], a[i] + m, make_pair(thres, -1)) - a[i];
        for (int j = start; j < m; ++j) {
            for (int k = j + 1; k < m; ++k) {
                if (was[ a[i][j].second ][ a[i][k].second ] == IT) return true;
                was[ a[i][j].second ][ a[i][k].second ] =
                was[ a[i][k].second ][ a[i][j].second ] =  IT;
            }
        }
    }
    return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int mx = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            scanf("%d", &x);
            if (x > mx) mx = x;
            a[i][j].first = x;
            a[i][j].second = j;
        }
        sort(a[i], a[i] + m);
    }
    int left = 0;
    int right = mx; 
    while (left < right) {
        int c = right - ((right - left) >> 1);
        if (Can(c)) left = c;else right = c - 1;
    }
    printf("%d\n", left);
    
    return 0;
}
