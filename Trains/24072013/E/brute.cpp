#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char buf1[11111], buf2[1111];
int ans[1111111];
int n;

int s(int x) {
    int ss = 0;
    while (x) {
        ss += x % 10;
        x /= 10;
    }
    return ss;
}

bool ByMagic(int x,int y) {
    if (s(x) < s(y)) return true;
    if (s(x) > s(y)) return false;
    sprintf(buf1, "%d", x);
    sprintf(buf2, "%d", y);
    return string(buf1) < string(buf2);
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) ans[i] = i;
    sort(ans + 1, ans + n + 1, ByMagic);
    for (int i = 1; i <= n; ++i)
        cout << i << ": " << ans[i] << endl;
    
    return 0;
}
