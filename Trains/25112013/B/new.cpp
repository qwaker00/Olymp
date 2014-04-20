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
        for (int c = 'a'; c <= 'y'; ++c) {
            int cnt = 0, mxA = 0, mxB = 0;
            for (int i = 0; i < n; ++i) if (A[i] == c || A[i] == c + 1) {
                ++cnt;
                if (cnt > mxA) mxA = cnt;
            } else cnt = 0;
            cnt = 0;
            for (int i = 0; i < n; ++i) if (B[i] == c || B[i] == c + 1) {
                ++cnt;
                if (cnt > mxB) mxB = cnt;
            } else cnt = 0;
            if (min(mxA, mxB) * 2 >= n) {
                positive = 1;
                break;
            }
        }
        puts(positive ? "POSITIVE" : "NEGATIVE");
    }
    
    return 0;
}
