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
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    int it = 0;
    cin >> T;
    while (T--) {
        ++it;

        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        for (int _i = 0; _i < N; ++_i) {
            int minv = 2e9;
            int mi = 0;
            for (int j = 0; j < (int)a.size(); ++j) if (a[j] < minv) {
                minv = a[j];
                mi = j;
            }
            ans += min(mi, (int)a.size() - mi - 1);
            a.erase(a.begin() + mi);
        }

        cout << "Case #" << it << ": " << ans << endl;
    }
    
    return 0;
}
