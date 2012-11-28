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


#define MOD 1000000007

int dd[111111], dn = 0;
char s[111111];
int n;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    LL ans = 0;
    cin >> s;
    n = strlen(s);
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) {
            bool good = true;
            
            for (int j = 0; j < dn; ++j) if (d % dd[j] == 0) {
                good = false;
                break;
            }

            for (int i = d; i < n && good; i++) if (s[i] != s[i - d]) {
                good = false;
                break;
            }

            if (good) {
                dd[dn++] = d;
                ans -= (n / d) - 1;
            }
        }
    }
    while (ans < 0) ans += MOD;
    LL ans1 = 0, ans2 = 1;
    for (int i = 1; i < n; i++) {
        ans2 = (ans2 * 26) % MOD;
        ans1 = (ans1 + ans2) % MOD;
    }
    cout << (ans1 + ans + MOD) % MOD << endl;
    
    return 0;
}
