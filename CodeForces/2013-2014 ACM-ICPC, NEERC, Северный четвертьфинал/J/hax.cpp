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

#define MOD 1000000000
#define N 111111

LL   S[N];
int  a[N];
LL   s[N];
int  n;
char ex[N];

char ops[N];
vector<LL> vals[N];
int on, vn;

void make_op() {
    if (ops[on - 1] == '+') {
        const vector<LL>&  b = vals[--vn];
        vector<LL>&        a = vals[vn - 1];
        if (a.size() < b.size()) a.resize(b.size());
        for (int i = 0; i < b.size(); ++i)
            a[i] = (a[i] + b[i]) % MOD;
    } else
    if (ops[on - 1] == '-') {
        const vector<LL>&  b = vals[--vn];
        vector<LL>&        a = vals[vn - 1];
        if (a.size() < b.size()) a.resize(b.size());
        for (int i = 0; i < b.size(); ++i)
            a[i] = (a[i] - b[i] + MOD) % MOD;
    } else
    if (ops[on - 1] == '*') {
        const vector<LL>&  b = vals[--vn];
        const vector<LL>&  a = vals[vn - 1];
        vector<LL> c(b.size() + a.size() - 1);
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < b.size(); ++j)
               c[i + j] = (c[i + j] + a[i] * b[j]) % MOD;
        vals[vn - 1] = c;
    } else
    if (ops[on - 1] == ':') {
        vector<LL>& a = vals[vn - 1];
        vector<LL> b(a.size() * 2 - 1);
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < a.size(); ++j)
                b[i + j] = (b[i + j] + a[i] * a[j]) % MOD;
        a = b;
    } else
    if (ops[on - 1] == '/') {
        vector<LL>& a = vals[vn - 1];
        LL x = 0;
        for (int i = 0; i < a.size(); ++i)
            x += (S[i] * a[i]) % MOD;
        a = vector<LL>(1, x % MOD);
    }
    --on;
}

int main() {
    freopen("j.in", "r", stdin);
    freopen("j.out", "w", stdout);
            
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        s[i] = 1;
    }
    for (int it = 0; it <= 15; ++it) {
        S[it] = 0;
        for (int i = 0; i < n; ++i) {
            S[it] += s[i];
            s[i] = (s[i] * a[i]) % MOD;
        }
        S[it] %= MOD;
    }

    int prevop = 1;
    scanf("\n"); gets(ex);
    for (int i = 0; ex[i]; ++i) {
        char ch = ex[i];
        if ( ch >= '0' && ch <= '9' ) {
            LL x = 0;
            while (ex[i] >= '0' && ex[i] <= '9') {
                x = x * 10 + ex[i] - 48;
                ++i;
            }
            --i;
            vals[vn++] = vector<LL>(1, x);
            prevop = 0;
        } else
        if ( ch == 'N' ) {
            vals[vn++] = vector<LL>(1, n);
            prevop = 0;
        } else
        if ( ch == 'X' ) {
            vals[vn++] = vector<LL>(1, 0);
            vals[vn - 1].push_back(1);
            prevop = 0;
        } else
        if (ch == '+' && ex[i + 1] == '/') {
            ops[on++] = '/';
            ++i;
            prevop = 1;
        } else
        if (ch == '*' && ex[i + 1] == ':') {
            ops[on++] = ':';
            ++i;
            prevop = 1;
        } else
        if (ch == '(') {
            ops[on++] = '(';
            prevop = 1;
        } else
        if (ch == ')') {
            while (on > 0 && ops[on - 1] != '(') make_op();
            --on;
            prevop = 0;
        } else {
            if (ch == '-') {
                if (prevop)
                    vals[vn++] = vector<LL>();
            }
            ops[on++] = ch;
            prevop = 1;
        }
    }
    while (on > 0) make_op();
    printf("%d\n", (int)vals[vn - 1][0]);
        
    return 0;
}
        