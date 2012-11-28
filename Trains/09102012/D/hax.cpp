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


#define N 111111

int stn, st[N];
LL s[N], ans, sum;
int a[N], n, c[N];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    s[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) s[i] = s[i + 1] + a[i];

    ans = LL(1e18);
    sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + s[i] < ans) {
            ans = sum + s[i];
        }

        if (stn && st[stn - 1] >= a[i]) {
            while (stn && st[stn - 1] > a[i]) {
                if (stn > 1 && st[stn - 2] >= a[i]) {
                    sum += LL(st[stn - 1] - st[stn - 2]) * c[stn - 1];
                    c[stn - 2] += c[stn - 1];
                    --stn;
                } else {
                    sum += LL(st[stn - 1] - a[i]) * c[stn - 1];
                    st[stn - 1] = a[i];
                }
            }
            ++c[stn - 1];
        } else {
            st[stn++] = a[i];
            c[stn - 1] = 1;
        }
    }
    if (sum < ans) ans = sum;
    cout << ans << endl;
    
   
    return 0;
}
