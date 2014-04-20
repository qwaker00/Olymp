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
    typedef long long ll;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

ll d,b,p,t;

ll calc(ll s) {
    //cerr << s << ": " << double(s) / (b - d) << endl;
    return (t * (b - d) + s - 1) / s;
}

int main() {
    freopen("video.in", "r", stdin);
    freopen("video.out", "w", stdout);
    

    cin >> d >> b >> t >> p;
        
    ll l = 1, r = d * p;
    ll need = calc(r);
    while (l < r) {
        ll s = (l + r) >> 1;

        if (calc(s) > need) l = s + 1;
        else r = s;
    }
    cout << l << endl;

    return 0;
}
