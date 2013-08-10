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


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    cin >> n;

    int lastgo = -100500;
    int lastactive = -100500;
    int active = false;
    int activeunder = false;
    int lasttype = 0;

    for (int i = 0; i < n; ++i) {
        cin >> x >> y;

        int timer = ((x[0] - 48) * 10 + x[1] - 48) * 60 + (x[3] - 48) * 10 + x[4] - 48;

        if (!active) {
            if (timer < lastgo + 90) {
                lastactive = lastgo;
                active = true;
                activeunder = 
                if (activetype == 0) ans -= 26;else ans -= 28;
                ans += 44;
            }
        }

        lastgo = timer;
        lasttype = (y == 'U');
    }
    
    return 0;
}
