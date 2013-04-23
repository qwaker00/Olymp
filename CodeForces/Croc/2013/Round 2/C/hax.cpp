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


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    

    
    int ans = 0;
    LL n;
    cin >> n;
    if (n % 3 != 0) {
        cout << 0 << endl;
        return 0;
    } else {
        int cnt = 0;
        for (int i = 1; i <= 300; ++i)
        for (int j = 1; j <= 300; ++j)
            for (int k = 1; k <= 300; ++k) {
                if ((i + j + k) * (i + j + k) * (i + j + k) - i * i * i - j * j* j - k * k * k == n) {
                    cerr << i << " " << j << " " << k << endl;
                    ++cnt;
                }
            }
        cerr << cnt << endl;

        n /= 3;
        for (LD a = 1; 8 * a * a * a <= n; ++a) {
            for (LD b = a; b * (2 * a * a + 4 * a * b + 2 * b * b) <= n; ++b) {
                LD c = ((-b*(b+a)-a*(b+a))+sqrtl((b*(b+a)+a*(b+a))*(b*(b+a)+a*(b+a))-4*b*a*(b+a)*(b+a))) / (2*(b+a));

                if (fabsl((a + b + c) * (a + b + c) * (a + b + c) - a*a*a - b*b*b - c*c*c - n) < 1) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
    cerr << clock() << endl;

    
    return 0;
}
