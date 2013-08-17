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


int n;
int a[111111];

int main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);    
    
    cin >> n;
    int mx = 2e9;
    int ansi = 0;
    for (int i = 1; i <= n; ++i) {
        if ( max( (n + i - 1) / i, i) <= mx) {
            mx = max((n + i - 1) / i, i);
            ansi = i;
        }
    }
    for (int i = 0; i < n; ++i) a[i] = i;
    int last = 0;
    for (int i = 0; i < ansi; ++i) {
        int add = -1;
        for (int j = 1; j <= n - last; ++j) {
            if (n - last - j <= (ansi - i - 1) * ansi) {
                add = j;
                break;
            }
        }
        if (add == -1) throw 1;
        reverse(a + last, a + add + last);
        last += add;
    }
    for (int i = 0; i < n; ++i) cout << a[i] + 1 << " ";
    cout << endl;
        
    return 0;
}
