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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char s[111][111];

int main() {
    freopen("ascii.in", "r", stdin);
    freopen("ascii.out", "w", stdout);

    int ans = 0, h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        for (int j = 0; j < w; j++) if (s[i][j] == '/' || s[i][j] == '\\') {
            int cnt = 0;
            for (int k = 0; k < i; k++) if (s[k][j] == '/' || s[k][j] == '\\') cnt++;
            if (cnt & 1) ans += i;else ans -= i;
        }
    }
    cout << ans << endl;
    
    return 0;
}
