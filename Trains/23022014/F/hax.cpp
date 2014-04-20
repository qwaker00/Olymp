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

const int N = 1000000;

int pr[N];
int pn, d[111], c[111];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    for (int i = 1; i <= N; ++i) {
        int s = 1;
        LL x = i;
        if (i == N) {
            x = 10200236032ll;
        }
        int dn = 0;
        for (int j = 0; j < pn && pr[j] * pr[j] <= x; ++j) {
            if (x % pr[j] == 0) {
                int ss = 1;
                d[dn] = pr[j];
                c[dn] = 0;
                while (x % pr[j] == 0) {
                    x /= pr[j];
                    ++c[dn];
                    ss *= pr[j];
                }

                s *= ((ss * pr[j]) - 1) / (pr[j] - 1);

                ++dn;
            }
        }
        if (x > 1) {
            if (dn == 0) {
                pr[pn++] = i;
            }
            d[dn] = x;
            c[dn] = 1;
            s *= x + 1;
            ++dn;
        }

        if (s >= 2 * i) {
            int A = s / __gcd(s, i);
            int B = i / __gcd(s, i);
            if (A <= 100 && B <= 100 && (A & 1) == 1) {
                cout << i << ": " << s << ": " << A << "/" << B << "  ";
                for (int j = 0; j < dn; ++j) cout << d[j] << "^" << c[j] << " ";
                cout << endl;
            }
        }
    }
    
    return 0;
}
