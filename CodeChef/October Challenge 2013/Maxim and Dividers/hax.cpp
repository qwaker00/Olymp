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


bool check(int x) {
    while (x) {
        if (x % 10 == 4 || x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int ans = 0, n;
        cin >> n;
        for (int i = 1; i * i <= n; ++i) if (n % i == 0){
            ans += check(i);
            if (i != n / i) 
                ans += check(n / i);
        }
        cout << ans << endl;
    }    
    return 0;
}
