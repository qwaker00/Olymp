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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T; 
    cin >> T;
    while (T--) {
        double Rf, Bf, Mf;
        cin >> Rf >> Bf >> Mf;
        LL R = LL(Rf * 100 + 1e-5);
        LL B = LL(Bf * 100 + 1e-5);
        LL M = LL(Mf * 100 + 1e-5);
        
        int it = 0;
        for (; it < 1200; ++it) {
            B += (B * R + 5000) / 10000;
            B -= min(B, M);
            if (B == 0) break;
        }
        if (it < 1200)
            cout << it + 1 << endl;else
            cout << "impossible" << endl;
    }
    
    return 0;
}
