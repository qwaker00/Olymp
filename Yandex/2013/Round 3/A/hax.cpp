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


int a[111];
int n;
int bad = 0, bsum = 0, sum = 0;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            bad++;
            bsum += a[i];
        } 
        sum += a[i];
    }

    cout.precision(15);
    cout << fixed;

    if (bad == 0) {
        cout << LD(sum) << endl;
        return 0;
    }
    if (bad == n) {
        cout << LD(bsum) / n << endl;
        return 0;
    }

    LD ans = LD(bsum) / bad;
    LD prob = 1;
    LD s = 0;
    for (int i = 0; i <= n - bad; ++i) {
        ans += prob * LD(bad) / (n - i) * (sum - bsum) * i / (n - bad);
        prob *= (n - i - bad) / LD(n - i);
    }
    cout << ans << endl;

    return 0;
}
