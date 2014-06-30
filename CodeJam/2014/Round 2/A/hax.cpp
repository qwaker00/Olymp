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
        int N, V;
        cin >> N >> V;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int ans = 0;
        for (int i = 0, j = N; i < j; ++i) {
            if (j - 1 > i && a[i] + a[j - 1] <= V) {
                --j;
            }
            ++ans;
        }
        cout << "Case #" << it << ": " << ans << endl;
    }
    
    return 0;
}
