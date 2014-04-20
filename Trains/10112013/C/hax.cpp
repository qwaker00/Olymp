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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int ans = 1e9 + 100;
    int n;
    cin >> n;    
    if (n == 7 * 3) {
        cout << 1 << endl;
    } else {
        for (int i = 1; i <= 6; ++i)
            for (int j = 1; j <= 6; ++j)
                if (n - i - j > 0 && (n - i - j) % 14 == 0 && (n - i - j) / 14 > 1) {
                    ans = min(ans, (n - i - j) / 14);
                }
        if (ans > 1e9)
            cout << -1 << endl;else
            cout << ans << endl;
    }

    
    return 0;
}
