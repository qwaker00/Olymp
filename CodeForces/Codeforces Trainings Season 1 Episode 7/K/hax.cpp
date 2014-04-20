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

#define N 555555

char s[N];
int prv[N][10];
int n, k, an = 0;
char ans[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d\n", &n, &k);
    k = n - k;
    gets(s);    

    memset(prv, 63, sizeof(prv));
    for (int i = n - 1; i >= 0; --i) {
        memcpy(prv[i], prv[i + 1], sizeof(prv[i]));
        prv[i][s[i] - '0'] = i;
    }

    int cur = 0;
    for (int i = 0; i < k; ++i) {
        int rest = k - i;
        for (int i = 9; i >= 0; --i)
            if (n - prv[cur][i] >= rest) {
                ans[an++] = i + '0';
                cur = prv[cur][i] + 1;
                break;
            }
    }
    puts(ans);
    
    return 0;
}
