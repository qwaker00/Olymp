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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    while (true) {
        int h1, h2, h3, w1, w2, w3;
        cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;
        if (h1 == 0) break;

        int ans = 2e9;
        for (int i = 0; i < 2; ++i) {
            for (int ii = 0; ii < 2; ++ii) {
                for (int iii = 0; iii < 2; iii++) {
                    int s = h1 * w1 + h2 * w2 + h3 * w3 - min(h1, h2) * min(w1, w2) - min(h1, h3) * min(w1, w3) - min(h3, h2) * min(w3, w2) + min(min(h1, h2), h3) * min(min(w1, w2), w3);
                    if (s < ans) ans = s;
                    swap(h1, w1);
                }
                swap(h2, w2);
            }
            swap(h3, w3);
        }

        cout << ans << endl;
    }
    
    return 0;
}
