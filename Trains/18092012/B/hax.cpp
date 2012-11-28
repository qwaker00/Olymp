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

const int N = 222222;
int n, d;

struct cell {
    int x, y, ind;

    bool operator <(const cell& A) const {
        return x < A.x;
    }
} a[N];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].ind = i;
    }
    sort(a, a + n);

    int l = 0;
    int b1 = -2, b2 = -2, ans = 0;
    int bl = 0;
    for (int i = 0; i < n; ++i) {
        while (l + 1 < i && a[i].x - a[l + 1].x >= d) {
            l++;
            if (a[l].y > a[bl].y) bl = l;
        }    

        if (a[i].x - a[bl].x >= d && a[i].y + a[bl].y > ans) {
            ans = a[i].y + a[bl].y;
            b1 = bl;
            b2 = i;
        }
    }

    cout << b1 + 1 << " " << b2 + 1 << endl;

    return 0;
}
