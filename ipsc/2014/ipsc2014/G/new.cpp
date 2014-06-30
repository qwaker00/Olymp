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

char mem[1111111];

char solve(vector<int>&p, int msk, int turns) {
    char& ans = mem[msk];
    if (ans != -1) return ans;
    for (int j = 0; j < (int)p.size(); ++j)
        if (p[j] >= turns && !(msk & (1 << j))) {
            if (!solve(p, msk ^ (1 << j), turns + 1)) {
                return ans = 1;
            }
        }
    return ans = 0;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            vector<int> p;
            for (int _i = 0; _i < i; _i++) p.push_back(_i);
            for (int _i = 0; _i < j; _i++) p.push_back(_i + i + 1);

            memset(mem, -1, sizeof(mem));
            cout << char(solve(p, 0, 0) + '0');
        }
        cout << endl;
    }
    return 0;


    int T;
    cin >> T;
    while (T--)  {
        int n;
        string s;
        cin >> n >> s;
        vector<int> p;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') p.push_back(i);
        }
        memset(mem, -1, sizeof(mem));
        cout << (solve(p, 0, 0) ? "Adam" : "Betka") << endl;
    }
    
    return 0;
}
