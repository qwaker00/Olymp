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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;
char s[100111], WAS[333][100111], wasall[256];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
//    gets(s);

/*    char ch;
    int l = 0;
    while ((ch = getchar())) {
        if (feof(stdin)) break;
        if (ch >= '0' && ch <= '9') s[l++] = ch;
    }
*/
    gets(s);
    int l = strlen(s);
    assert(l >= 1 && l <= 100000);

    WAS[0][0] = 1;
    int ans = 0;
    while (true) {
        char *was = WAS[ans], *wass = WAS[ans + 1];

        if (was[l - 1]) break;

        for (int i = 0; i < l; ++i)
            if (was[i])
                wasall[s[i]] = 1;

        for (int i = 0; i < l; ++i)
            if (was[i] || wasall[s[i]] || (i > 0 && was[i - 1]) || (i + 1 < l && was[i + 1]))
                wass[i] = 1;

        ++ans;
    }
    printf("%d\n", ans);
    
    return 0;
}
