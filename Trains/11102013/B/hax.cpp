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

char s1[3333], s2[3333], s3[3333];
int lst[33];
int nxt[1555];
int u[1555];

int Solve(char * a, int an, char * B, int bn) {
    int ans = 0;
    for (int sh = 0; sh < bn; ++sh) {
        char * b = B + sh;

        memset(lst, -1, sizeof(lst));
        for (int i = an - 1; i >= 0; --i) {
            nxt[i] = lst[a[i] - 'a'];
            lst[a[i] - 'a'] = i;
        }
        int un = 0;
        for (int i = 0; i < bn; ++i) {
            int x = lst[ b[i]  - 'a' ];
            if (x == -1) continue;
            
            int p = lower_bound(u, u + un, x) - u;
            if (p == un) u[un++] = x;else u[p] = x;

            lst[b[i] - 'a'] = nxt[x];
        }
        if (un > ans) ans = un;
    }
    return ans;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    scanf("%s%s", s1, s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    memcpy(s2 + n2, s2, n2);
    strcpy(s3, s2);
    reverse(s3, s3 + n2 + n2);
    cout << max(Solve(s1, n1, s2, n2), Solve(s1, n1, s3, n2)) * 2 << endl;
    
    return 0;
}
