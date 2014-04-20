#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

typedef unsigned long long ULL;
using namespace std;

int gcd(int x, int y) {
    if (x == 0 && y == 0) return -1;
    if (y == 0) return x;
    return gcd(y, x % y);
}

#define MAXX 5000

int G[MAXX][MAXX];

vector<int> a, b;
int n, k, ans;

void rec(int i, int x, int s) {
    if (i == n) {
        ans = s;
        for (int j = 0; j < n; ++j) cerr << b[j] << " ";
        cerr << endl;
        return;
    }
    x = max(a[i], x);
    while (s + x * (n - i) < ans && x < MAXX) {
        bool bad = false;        
        for (int j = 0; j < i; ++j) if (G[b[j]][x] != k) {
            bad = true;
            break;
        }
        if (bad) {
            ++x;
            continue;
        }
        b[i] = x;

//        for (int j = 0; j < i; ++j) putc(' ', stderr);
//        fprintf(stderr, "%d\n", x);
        
        rec(i + 1, x, s + x);
        ++x;
    }
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    for (int i = 0; i < MAXX; ++i) {
        for (int j = 0; j < MAXX; ++j)
            G[i][j] = __gcd(i, j);
    }
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        time_t start = clock();
        cin >> n >> k;
        a.assign(n, 0);
        b.assign(n, 0);
        int zeroc = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s += a[i];
            if (a[i] == 0) a[i] = (zeroc > 0);
            ++zeroc;
        }
        sort(a.begin(), a.end());
        ans = 2e9;
        rec(0, 0, 0);
        assert(ans < 1e9);
        printf("Case #%d: %d\n", __it, ans - s);
        cerr << "Time: " << clock() - start << endl;
    }   
    
    return 0;
}
