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

const int N = 222222;

char a[N], b[N];
int la, lb, pb[N], bc[N], last[N];
vector<int> ans;

inline bool eq(int ac, int bc, int pos) {
    return (ac == bc || (bc == -1 && pos - ac < 0));
}

int main() {
    freopen("substring.in", "r", stdin);
    freopen("substring.out", "w", stdout);
    
    gets(a);
    gets(b);

    la = strlen(a);
    lb = strlen(b);

    memset(last, -1, sizeof(last));
    for (int i = 0; i < lb; ++i) {
        bc[i] = last[ b[i] ] == -1 ? -1 : i - last[ b[i] ];
        last[ b[i] ] = i;
    }

    pb[0] = 0;
    for (int i = 1; i < lb; ++i) {
        int& k = pb[i] = pb[i - 1];
        while (k > 0 && !eq(bc[i], bc[k], k) ) k = pb[k - 1];
        if (eq(bc[i], bc[k], k)) ++k;else k = 0;
    }

    memset(last, -1, sizeof(last));
    int k = 0;
    for (int i = 0; i < la; ++i) {
        int code = last[ a[i] ] == -1 ? -1 : i - last[ a[i] ];
        last[ a[i] ] = i;

        while (k > 0 && !eq(code, bc[k], k) ) k = pb[k - 1];
        if (eq(code, bc[k], k)) ++k;else k = 0;

        if (k == lb) {
            ans.push_back(i - lb);
        }
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d ", ans[i] + 2);        
    }
    puts("");
    
    return 0;
}
