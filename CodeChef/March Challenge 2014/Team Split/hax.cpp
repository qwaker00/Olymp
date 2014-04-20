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

int cnt[1000111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b, c, d, x;
        scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

        x = d;
        ++cnt[x];
        for (int i = 1; i < n; ++i) {
            x = (LL(a) * x * x + LL(b) * x + c) % 1000000;
            ++cnt[x];
        }

        LL t[2] = {0, 0};
        int turn = 0;

        for (int i = 999999; i >= 0; --i) if (cnt[i]) {
            t[0] += LL(cnt[i] >> 1) * i;
            t[1] += LL(cnt[i] >> 1) * i;
            t[turn] += LL(cnt[i] & 1) * i;
            turn ^= cnt[i] & 1;
            cnt[i] = 0;
        }
//        for (int i = 999999; i >= 0; --i) while (cnt[i]) {
//            t[turn] += i;
//            turn ^= 1;
//            --cnt[i];
//        }

        printf("%lld\n", llabs(t[0] - t[1]));
    }
    cerr << clock() << endl;
    
    return 0;
}
