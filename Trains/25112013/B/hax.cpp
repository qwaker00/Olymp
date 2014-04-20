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

char A[1111], B[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d\n%s\n%s", &n, A, B);

        int positive = 0;
        for (int dx = -n; dx <= n && !positive; ++dx) {
            int c = 0;
            for (int i = max(-dx, 0); i < n && i + dx < n; ++i) {
                if (abs(A[i] - B[i + dx]) <= 1) {
                    ++c;
                    if (c + c >= n) {
                        positive = true;
                        break;
                    }
                } else c = 0;
            }
        }
        puts(positive ? "POSITIVE" : "NEGATIVE");
    }
    
    return 0;
}
