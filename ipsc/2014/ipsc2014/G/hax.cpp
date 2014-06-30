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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int mem[1111][1111];

int solve(int x, int y) {
    if (x == 0 && y == 0) return 0;
    if (mem[x][y] != -1) return mem[x][y];

    set<int> v;
    for (int i = 0; i < x; ++i) {
        if (i == 0)
            v.insert( solve(x - 1, y) );
        else
            v.insert( solve(i - 1, y + x - i - 1) );
    }
    if (y > 0)    
        v.insert( solve(max(0, x - 1), y - 1) );

    int& ans = mem[x][y] = 0;
    while (v.find(ans) != v.end()) ++ans;
    return ans;
}

int solve2(int cnt1, int cnt2) {
    if (cnt1 == 0)
        return cnt2&1;
    else if (cnt1 == 1)
        return 1;
    else if (cnt1 == 2)
        return 1 - (cnt2&1);
    else if (cnt1 == 3)
        return cnt2 > 0;
    else
        return 1;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    memset(mem, -1, sizeof(mem));

    solve(0, 1);
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
//            putchar('0' + (solve(i, j) > 0));
            assert( (solve(i, j) > 0) == solve2(i, j) );
        }
//        puts("");
    }


    int T;
    cin >> T;
    while (T--)  {
        int n;
        string s;
        cin >> n >> s;

        int cnt1 = 0, cnt2 = 0;
        while (s[cnt1] == '1') ++cnt1;
        for (int i = cnt1; i < n; ++i) cnt2 += s[i] == '1';
        bool ans = solve2(cnt1, cnt2);
        cout << (ans ? "Adam" : "Betka") << endl;
    }
    
    return 0;
}
