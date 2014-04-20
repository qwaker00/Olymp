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

struct Tp {
    int x, y, i;

    bool operator<(const Tp& t) const {
        return y < t.y;
    }
} a[111111];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int n;
    scanf("%d", &n);
    for (int i= 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].i = i;
    }
    sort(a, a + n);
    LL l = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
        if (a[i].x >= l) { 
            l += a[i].y;
            ans.push_back(a[i].i);
        }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << " ";
    cout << endl;
    
    return 0;
}
