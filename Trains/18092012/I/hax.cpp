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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char s[1111111], good[1111111];
int n, last;


int main() {
//    freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);

    gets(s);
    n = strlen(s);
    last = -1;
    for (int i = 0; i < n; ++i)
        if (s[i] == '(') last = i;else {
            if (s[i] == ')' && last != -1) {
                good[last] = 1;
                last = -1;
            }
            if (s[i] != ' ' && (s[i] <'a' || s[i] >'z') && (s[i] <'A' || s[i]>'Z')) last = -1;
        }
    last = -1;
    for (int i = n - 1; i >= 0; --i)
        if (s[i] == ')') last = i;else {
            if (s[i] == '(' && last != -1) {
                good[last] = 1;
                last = -1;
            }
            if (s[i] != ' ' && (s[i] <'a' || s[i] >'z') && (s[i] <'A' || s[i]>'Z')) last = -1;
        }

    int ans = 0;
    for (int i = 0; i < n; i++) if ((s[i] == ')' || s[i] == '(') && !good[i]) ++ans;
    cout << ans << endl;

    return 0;
}
