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

#define N 111

int n, t[N], h[N], m[N], q, hh, mm, tt;
char name[N][111];


int main() {
    freopen("timetable.in", "r", stdin);
    freopen("timetable.out", "w", stdout);

    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d\n%s\n", &h[i], &m[i], name[i]);
        t[i] = h[i] * 60 + m[i];
    }    
    t[n] = t[0] + 24 * 60;
    strcpy(name[n], name[0]);

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d:%d\n", &hh, &mm);
        tt = hh * 60 + mm;
        for (int j = 0; j <= n; ++j) {
            if (t[j] >= tt) {
                int td = t[j] - tt;
                printf("%02d:%02d\n%s\n", td / 60, td % 60, name[j]);
                break;
            }
        }
    }

    return 0;
}
