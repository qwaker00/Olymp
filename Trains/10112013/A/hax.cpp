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

#define N 222222

struct Tp {
    int x, w, i;
} a[N];
int n, d;

int mx, ans, mi, ansi, ansj;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].w);
        a[i].i = i;
    }
    mi = -1;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < i && a[i].x - a[j].x >= d) {
            if (a[j].w > mx) {
                mx = a[j].w;
                mi = j;
            }
            ++j;
        }
        if (mi != -1 && mx + a[i].w > ans) {
            ans = mx + a[i].w;
            ansi = i;
            ansj = mi;
        }
    }
    if (mi == -1)
        cout << -1 << " " << -1 << endl;else
        cout << ansi + 1 << " " << ansj + 1 << endl;
    
    return 0;
}
