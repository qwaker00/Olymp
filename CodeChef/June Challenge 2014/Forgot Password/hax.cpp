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

char rule[128];
char s[1000111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        for (int i = 0; i < 128; ++i) rule[i] = i;
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i) {
            char x, y;
            scanf("%c %c\n", &x, &y);
            rule[x] = y;
        }
        gets(s);

        int pt = 0;
        int l = 0, r = 0;
        for (; s[r]; ++r) {
            s[r] = rule[s[r]];
            pt |= (s[r] == '.');
        }

        while (s[l] == '0') ++l;
        if (pt)
            while (s[r - 1] == '0') --r;
        if (s[r - 1] == '.') --r;

        if (l >= r) {
            puts("0");
        } else {
            s[r] = 0;
            puts(s + l);
        }
    }
    
    return 0;
}
