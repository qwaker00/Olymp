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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    vector<ULL> ans;

    ULL N;
    cin >> N;
    for (int p = 0; p <= 60; ++p) {
        ULL left = 1;
        ULL right = sqrtl(2 * N) + 2;
        while (left < right) {
            ULL c = (left + right + 1) >> 1;
            if (LD(c) * (LD(c) + ((1ll << (p + 1)) - 3)) > 5e18) right = c - 1;else
            if (c * c + c * ((1ll << (p + 1)) - 3) > 2 * N) right = c - 1;else
                left = c;
        }
        if (left * left + left * ((1ll << (p + 1)) - 3) == 2 * N && (left & 1) == 1) {
            for (int i = 0; i < p; ++i) left *= 2;
            ans.push_back(left);
        }
    }
    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
    
    return 0;
}
