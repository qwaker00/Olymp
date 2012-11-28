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

void Imp() {
    puts("Impossible");
    exit(0);
}

void Un() {
    puts("Unique");
    exit(0);
}

void Amb() {
    puts("Ambiguous");
    exit(0);
}

int main() {
    freopen("black.in", "r", stdin);
    freopen("black.out", "w", stdout);

    int n, m, s, k;
    char ch;

    cin >> m >> n >> s >> k;

    int st = 0, c = 0;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if (ch == '*') {
            if (st == 0) {
                st = 1;
                c = 1;
            } else
            if (st == 1) {
                ++c;
            } else
            if (st == 2) {
                Imp();
            }
        } else
        if (st == 1) st = 2;
    }
    if (st == 2 || st == 1) {
        if (c != s) Imp();
        if (s == 1 || m == s || k == 1 || k == m) Un(); else Amb();
    } else if (st == 0) {
        if (max(k - 1, m - k) < s) Imp();
        if (s == n && (k - 1 < s || (m - k) < s)) Un();
        Amb();
    }
    throw 1;
    
    return 0;
}
