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

inline LL det(int b1, int b2, int b3, int b4, int b5, int b6, int b7, int b8, int b9) {
    return b1 * b5 * b9 + b2 * b6 * b7 + b3 * b4 * b8 - b3 * b5 * b7 - b1 * b6 * b8 - b2 * b4 * b9;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    
    int T;
    cin >> T;
    while (T--) {
        int n, a[22];
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];

        // d = 1
        {
            if (a[1] % a[0] == 0) {
                int a0 = a[1] / a[0];

                bool good = true;
                for (int i = 1; i < n; ++i)
                    if (a[i] != a[i - 1] * a0) {
                        good = false;
                        break;
                    }

               if (good) {
                    cout << a[n - 1] * a0 << endl;
                    continue;
               }
            }
        }

        // d = 2
        {
            int D = a[0] * a[2] - a[1] * a[1];
            int Dx = a[2] * a[2] - a[3] * a[1];
            int Dy = a[0] * a[3] - a[1] * a[2];
            if (D != 0 && Dx % D == 0 && Dy % D == 0) {
                Dx /= D;
                Dy /= D;

                bool good = true;
                for (int i = 2; i < n; ++i)
                    if (a[i] != a[i - 1] * Dy + a[i - 2] * Dx) {
                        good = false;
                        break;
                    }
                if (good) {
                    cout << a[n - 2] * Dx + a[n - 1] * Dy << endl;
                    continue;
                }
            }
        }

        // d = 3
        {
            LL D = det(a[0], a[1], a[2],
                       a[1], a[2], a[3],
                       a[2], a[3], a[4]);
            LL D1 = det(a[3], a[1], a[2],
                        a[4], a[2], a[3],
                        a[5], a[3], a[4]);
            LL D2 = det(a[0], a[3], a[2],
                        a[1], a[4], a[3],
                        a[2], a[5], a[4]);
            LL D3 = det(a[0], a[1], a[3],
                        a[1], a[2], a[4],
                        a[2], a[3], a[5]);
           if (D != 0 && D1 % D == 0 && D2 % D == 0 && D3 % D == 0) {
                D1 /= D;
                D2 /= D;
                D3 /= D;
                
                bool good = true;
                for (int i = 3; i < n; ++i)
                    if (a[i] != a[i - 3] * D1 + a[i - 2] * D2 + a[i - 1] * D3) {
                        good = false;
                        break;
                    }
                if (good) {
                    cout << a[n - 3] * D1 + a[n - 2] * D2 + a[n - 1] * D3 << endl;
                    continue;
                }
            }
        }

        while (true);
    }
        
    return 0;
}
