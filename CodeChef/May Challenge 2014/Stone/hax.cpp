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

LL a[111111];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }    

    if (k) k = ((k - 1) % 2) + 1;
    for (int i = 0; i < k; ++i) {
        LL mii = *max_element(a, a + n);
        for (int j = 0; j < n; ++j) a[j] = mii - a[j];
    }
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}
