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


int n, m, k, p;
char buf[11111];
int bad[26];

LL A[111][111];

struct TLong {
    vector<char> a;

    TLong() {
        a.push_back(0);
    }

    TLong(const vector<char>& v) : a(v) { }

    TLong(LL x) {
        while (x) {
            a.push_back(x % 10);
            x /= 10;
        }
    }

    operator bool() {
        return a.size() > 1 || a[0] != 0;
    }

    TLong operator+(const TLong& b) {
        int l = max(b.a.size(), a.size());
        vector<char> c(l);
        int carry = 0;
        for (int i = 0; i < l; ++i) {
            carry += (i < a.size() ? a[i] : 0) + (i < b.a.size() ? b.a[i] : 0);
            if (carry >= 10)
                c[i] = carry - 10, carry = 1;else
                c[i] = carry, carry = 0;
        }
        if (carry)
            c.push_back(carry);
        return c;
    }

    TLong operator*(const LL b) {
        LL carry = 0;
        vector<char> c(a.size());
        for (int i = 0; i < a.size(); ++i) {
            carry += a[i] * b;
            c[i] = carry % 10;
            carry /= 10;
        }
        while (carry) {
            c.push_back(carry % 10);
            carry /= 10;
        }
        return c;
    }

    friend ostream& operator<<(ostream& out, const TLong& a) {
        for (int i = a.a.size() - 1; i >= 0; --i) {
            out << char(a.a[i] + 48);
        }
        return out;
    }
};


TLong f1[111][111];
TLong f2[111][111];
//TLong Al[111][111];

int main() {
    freopen("parallel.in", "r", stdin);
    freopen("parallel.out", "w", stdout);
    
    scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < m; ++i) 
        bad[i] = (1 << m) - 1;
    for (int i = 0; i < p; ++i) {
        scanf("%s", buf);
        bad[ buf[0] - 'A' ] &= ~(1 << (buf[1] - 'A'));
        bad[ buf[1] - 'A' ] &= ~(1 << (buf[0] - 'A'));
    }

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= i; ++j) {
            A[i][j] = 1;
            for (int l = i - j + 1; l <= i; ++l) A[i][j] *= l;
//            Al[i][j] = TLong(A[i][j]);
        }
    }

    scanf("%s", buf);
    f1[0][0] = 1;
    f2[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) if (f1[i][j]) {
            int msk = 0;
            for (int l = 1; l <= k; ++l) {
                if (bad[ buf[i + l - 1] - 'A' ] & msk) break;
                msk |= (1 << (buf[i + l - 1] - 'A'));
                f1[i + l][j + 1] = f1[i + l][j + 1] + f1[i][j];
                f2[i + l][j + 1] = f2[i + l][j + 1] + f2[i][j] * A[k][l];
            }
        }
    }

    for (int i = 0; i <= n; ++i) if (f1[n][i]) {
        cout << i << endl;
        cout << f1[n][i] << endl;
        cout << f2[n][i] << endl;
        return 0;
    }
    
    return 0;
}
