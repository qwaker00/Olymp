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
typedef long double ld;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 1111;

int n, l;
ld x[N];

const int M = 6666666;
pair<ld, int> a[M];
int ke;

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);


    if (l == 1) {
        cout << 10 << endl;
        return 0;
    }

    int maxC = int(ld(x[n - 1]) / ld(l) / 0.1) + 1;

    cout.precision(15);
    cout << fixed;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j) {
            ld x1 = x[i], x2 = x[j];
            for (int k = 0; k <= maxC; ++k) {
                ld A, B;
                if (k == 0) {
                    A = x1 - x2;
                    B = 10. + 1e-10;    
                } else {
                    A = (x1 - x2) / ld(l * k + 1.);
                    B = (x1 - x2) / ld(l * k - 1.); 
                }
                A += 1e-12;
                B -= 1e-12;
                if (A > B) continue;

                if (B < 0.1 || A > 10.) continue;

                A = max(ld(0.05), A);
                B = min(ld(10.0), B);
                
                a[ke].first = A;
                a[ke].second = 1;
                ++ke;
                a[ke].first = B;
                a[ke].second = -1;
                ++ke;

                //cout << x1 << "  vs  " << x2 << "  at " << k << " turns" << endl;
                //cout << A << " " << B << endl;
            }
        }

    sort(a, a + ke);


    if (ke == 0 || a[ke - 1].first + 1e-10 < 10.0) {
        cout << 10.0 << endl;
        return 0;
    }
    int st = 0;
    for (int i = ke - 1; i >= 0; --i) {
        st += a[i].second;
        if (st == 0) {
            if (a[i].first + 1e-10 < 0.1) {
                puts("no fika");
                return 0;
            }    
            cout.precision(15);
            cout << fixed;
            cout << a[i].first << endl;
            return 0;
        }
    }

    puts("no fika");

    return 0;
}
