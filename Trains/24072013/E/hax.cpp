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

LL k, n;
int sn = 0;
int s[111], ss[111], ssn = 0;

LL mem1[222][22];
LL mem2[222][22];

LL Calc(int su, int l) {    
    if (l == 0) return su == 0;
    if (su < 0) return 0;
    if (l < 0) return 0;
    LL& ans = mem1[su][l];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = 0; i <= 9; ++i) {
        ans += Calc(su - i, l - 1);
    }
    return ans;
}

LL Calc(int su, int* s, int sn, bool first) {
    if (su < 0) return 0;
    if (sn == 0) return su == 0;

    LL& ans = mem2[su][sn];
    if (ans != -1) return ans;

    ans = 0;
    for (int i = first; i <= 9; ++i) {
        if (i < s[sn - 1])
            ans += Calc(su - i, sn - 1);else
        if (i == s[sn - 1])
            ans += Calc(su - i, s, sn - 1, false);
    }
    return ans;
}

int main() {
    freopen("grlex.in", "r", stdin);
    freopen("grlex.out", "w", stdout);

    memset(mem1, -1, sizeof(mem1));
    memset(mem2, -1, sizeof(mem2));

    cin >> n >> k;
    LL K = k;

    while (n) {
        s[sn++] = n % 10;
        n /= 10;
    }

    for (int su = 1; su <= 180; ++su) {
        LL c = Calc(su, s, sn, false);
        if (c >= k) {
            bool eq = true;
            int it = 0;
            int ssu = su;
            while (k) {
                if (ssu == 0 && k == 1) break;
                if (ssu == 0) --k;
                for (int i = (it == 0); i <= 9; ++i) {
                    LL cc = 0;
                    for (int j = 0; j <= sn; ++j) {
                        if (eq) {
                            if (i < s[sn - it - 1]) {
                                cc += Calc(ssu - i, j - it - 1);
                            } else
                                if (i > s[sn - it - 1]) {
                                    cc += Calc(ssu - i, j - it - 2);
                                } else {
                                    cc += Calc(ssu - i, s, sn - 1, false);
                                }
                        } else {                       
                            cc += Calc(ssu - i, j - it - 1);
                        }
                    }
                    if (cc >= k) {
                        cout << i;
                        eq &= s[sn - 1 - it] == i;
                        ssu -= i;
                        break;
                    }
                    k -= cc;
                }
                ++it;
            }
            break;
        }
        k -= c;
    }

    LL ans = 0;
    int kk = K, su = 0;
    while (kk > 0) {
        ss[ssn++] = kk % 10;
        su += kk % 10;
        kk /= 10;
    }

    for (int i = 1; i < su; ++i) ans += Calc(i, s, sn, false);
    ans += Calc(su, ssn - 1);
    for (int i = 0; i < ssn; ++i) {
        for (int d = 0; d < ss[ssn - i - 1]; ++d) {
            ans += Calc(su - d, ssn - i - 1);
        }
        su -= ss[ssn - i - 1];
    }

    cout << " " << ans << endl;
    
    return 0;
}
