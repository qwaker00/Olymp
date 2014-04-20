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

int cnt[222];
char s[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d\n", &T);
    while (T--) {
        gets(s);
        int l = strlen(s);

        int mx = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < l; ++i) {
            if (s[i] < 'A' || s[i] > 'Z') continue;
            ++cnt[s[i]];
            if (cnt[s[i]] > mx) {
                mx = cnt[s[i]];
            }
        }

        int target = -1;
        for (int i = 'A'; i <= 'Z'; ++i)
            if (cnt[i] == mx) {
                if (target != -1) {
                    target = -2;
                    break;
                }
                target = i;
            }
        if (target == -2) {
            puts("NOT POSSIBLE");
            continue;
        }
        printf("%d ", (target - 'E' + 26 * 10) % 26);
        for (int i = 0; i < l; ++i) {
            if (s[i] < 'A' || s[i] > 'Z') putchar(s[i]);else
                                        putchar( (s[i] - 'A' - target + 'E' + 26 * 10) % 26 + 'A' );
        }
        puts("");
    }
    
    return 0;
}
