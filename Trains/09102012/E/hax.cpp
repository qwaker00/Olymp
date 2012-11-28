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

struct Tp{
    int x, d, i;

    bool operator<(const Tp& B)const{
        return x < B.x;
    }
} a[111111];
int n, diff, killed[111111];
double al;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
          cin >> a[i].x;
          a[i].i = i;
    }
    for (int i = 0; i < n; i++) {
          cin >> al;
          a[i].d = 180000 - int(al * 1000 + 1e-10);
    }

    sort(a, a + n);

    set<int> s;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && a[j + 1].x == a[i].x) ++j;

        for (int k = i; k <= j; k++) {
            if (a[k].d < 90000) {
                diff = 90000 - a[k].d;
                set<int>::iterator j = s.lower_bound(diff);
                if (j == s.begin()) continue;
                killed[a[i].i] = true;
            }
        }
        for (int k = i; k <= j; k++) {
            s.insert(abs(90000 - a[k].d));
        }
    }

    s.clear();
    reverse(a, a + n);
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && a[j + 1].x == a[i].x) ++j;

        for (int k = i; k <= j; k++) {
            if (a[k].d > 90000) {
                diff = a[k].d - 90000;
                set<int>::iterator j = s.lower_bound(diff);
                if (j == s.begin()) continue;
                killed[a[i].i] = true;
            }
        }
        for (int k = i; k <= j; k++) {
            s.insert(abs(90000 - a[k].d));
        }
    }

    int ans = 0;
    for (int i =0 ; i < n; i++) ans += killed[i];
    cout << ans << endl;

    return 0;
}
