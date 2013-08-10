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

struct Tp {
    int x, y;
} a[33];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    int T;
    scanf("%d", &T);
    for (int __it = 0; __it < T; ++__it) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int A1 = (- a[i].x + a[j].x) * 2;
                int B1 = (a[j].y - a[i].y) * 2;
                int C1 = - A1 * (a[i].x + a[j].x) / 2 - B1 * (a[i].y + a[j].y) / 2;

                for (int k = j + 1; k < n; ++k) {
                    int A2 = (- a[i].x + a[k].x) * 2;
                    int B2 = (a[k].y - a[i].y) * 2;
                    int C2 = - A2 * (a[i].x + a[k].x) / 2 - B2 * (a[i].y + a[k].y) / 2;

                    cnt += n - 3;
                    if (A1 * B2 == A2 * B1) continue;
                    int d = A1 * B2 - A2 * B1;
                    double cx = double(-C1 * B2 + C2 * B1) / d;
                    double cy = double(-A1 * C2 + C1 * A2) / d;
                    double R = sqr(a[i].x - cx) + sqr(a[i].y - cy);
                    for (int ai = 0; ai < n; ++ai)
                        if (ai != i && ai != j && ai != k) {
                            if (sqr(a[ai].x - cx) + sqr(a[ai].y - cy) <= R + 1e-6) {
                                ++ans;
                            }
                        }
                }
            }
        }
        if (cnt == 0) cnt = 1;  
        cout.precision(12);
        cout << fixed << double(ans) / cnt << endl;
    }
    
    return 0;
}
