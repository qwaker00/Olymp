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

#define N 55

struct TLong {
    vector<char> digits;

    inline void push_back(int x) {
        digits.push_back(x);
    }

    inline char& operator[](int i) {
        return digits[i];
    }

    inline int size() {
        return digits.size();
    }

    inline operator bool() {
        return digits.size() > 0;
    }

    inline friend ostream& operator<<(ostream& o, TLong& x) {
        for (int i = x.size() - 1; i >= 0; --i) {
            o << char(x[i] + 48);
        }
        return o;
    }
} f[N][N][N];

void One(TLong& x) {
    x.digits.clear();
    x.push_back(1);
}
void Add(TLong& a, const TLong& B) {
    TLong b = B;
    if (b.size() > a.size()) a.digits.resize(b.size());
    if (a.size() > b.size()) b.digits.resize(a.size());
    int carry = 0, end = max(a.size(), b.size());
    for (int i = 0; i < end; ++i) {
        a[i] += carry + b[i];
        carry = a[i] / 10;
        a[i] %= 10;
    }
    if (carry) {
        a.push_back(carry);
    }
}

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);

    int n = 52, k = 52;
    One(f[1][1][1]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int l = 0; l <= k; ++l) if (f[i][j][l]) {
                if (i + 1 <= n)
                    Add(f[i + 1][j][max(l, i + 1 - j)], f[i][j][l]);
                if (j + 1 <= i)
                    Add(f[i][j + 1][l], f[i][j][l]);
            }
        }
    }
    int it = 0;
    while (true) {
        int n, k;
        cin >> n >> k;
        if (n + k == 0) break;
        if (it) cout << endl;
        cout << "Case " << (++it) << ": " << f[n + 1][n + 1][k] << endl;
    }
    
    return 0;
}
