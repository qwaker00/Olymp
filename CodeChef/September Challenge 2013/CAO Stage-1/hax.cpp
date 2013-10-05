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

string s[55];
#define ch(x, y) (((x)>=0)&&((y)>=0)&&((x)<n)&&((y)<m)&&(s[x][y]=='^'))

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m, ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> s[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ch(i, j) && ch(i - 1, j) && ch(i - 2, j) &&
                                ch(i + 1, j) && ch(i + 2, j) &&
                                ch(i, j + 1) && ch(i, j + 2) &&
                                ch(i, j - 1) && ch(i, j - 2)
                ) {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
