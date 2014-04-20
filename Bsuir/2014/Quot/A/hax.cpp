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

int val[1111111], wt[1111111], was[1111111];
char a[111111], b[111111], p[111111];
LL C;

LL powmod(LL a, LL b, LL c) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (res * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    gets(a);
    gets(b);
    cin >> C;

    LL A = 0;
    for (int i = 0; a[i]; ++i) A = (A * 10 + a[i] - '0') % C;

    if (strlen(b) < 10) {
        int B;
        sscanf(b, "%d", &B);
        printf("%d\n", (int)powmod(A, B, C));
    } else {            
        LL AA = A;
        int it = 0;
        while (!was[AA]) {
            val[it] = AA;
            was[AA] = 1;
            wt[AA] = it++;
            AA = (AA * A) % C;
        }

        int lb = strlen(b);
        reverse(b, b + lb);
        for (int i = 0; i < lb; ++i) b[i] -= '0';

        int Period = it - wt[AA], PredPeriod = wt[AA];

        int carry = 0;
        int x = PredPeriod;
        for (int i = 0; i < lb; ++i) {
            carry = b[i] - (x % 10) + carry;
            if (carry < 0)
                b[i] = carry + 10, carry = -1;
            else
                b[i] = carry, carry = 0;
            x /= 10;
        }

        LL B = 0;
        for (int i = lb - 1; i >= 0; --i) {
            B = (B * 10 + b[i]) % Period;
        }

        if (B == 0) B = Period;
        cout << val[PredPeriod + B - 1] << endl;
    }
        
    return 0;
}
