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

#include <ext/rope>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define M 1000000007
         
int n, a[2222], from[2222];
int C3 = 0;

int mem[2222][4444];

int calc(int x, int y, int c) {
    if (c == C3) return 1;

    int& ans = mem[c][x+y];
    if (ans != -1) return ans;
    int z = C3 - c - y;

    ans = 0;
    if (y > 0) {
        if (x && y)
            ans = (LL(x) * calc(x - 1, y - 1, c + 1)) % M;
        if (z)
            ans = (ans + LL(z) * calc(x, y, c + 1)) % M;
    } else {        
        if (x)
            ans = (LL(x) * calc(x, y, c + 1)) % M;
        if (z > 1)
            ans = (ans + LL(z - 1) * calc(x + 1, y + 1, c + 1)) % M;
    }

    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    vector<int> v;
    scanf("%d", &n);    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] != -1) {
            from[a[i]] = i;
        }
        v.push_back(a[i]);
    }
    memset(mem, -1, sizeof(mem));
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != -1 && from[i] == 0) ++c1;else
        if (a[i] == -1) {
            ++c3;
            if (from[i] != 0) ++c2;
        }
    }
    C3 = c3;
    cout << calc(c1, c2, 0) << endl;

    return 0;
}
