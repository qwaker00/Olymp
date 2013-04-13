#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
//#include <math.h>
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


#define MOD 1000000007

vector< pair<ULL, ULL> > all;
int n, k, x[111], y[111], xx[111111], yy[111111], xn = 0, yn = 0;

pair<ULL, ULL> CalcH(int xx, int yy) {
     ULL h1 = 0, h2 = 0;
     for (int k = 0; k < n; ++k) {
         if (x[k] >= xx && x[k] <= xx + k && y[k] >= yy && y[k] <= yy + k) {
             h1 = h1 * 37 + k;
             h2 = (h2 * 37 + k) % MOD;
             cerr << k << " ";
         }
     }
     cerr << endl;
     return make_pair(h1, h2);
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        xx[xn++] = x[i];
        xx[xn++] = x[i] - k;
        xx[xn++] = x[i] + k;
        xx[xn++] = x[i] - 1;
        xx[xn++] = x[i] + 1;
        xx[xn++] = x[i] - k - 1;
        xx[xn++] = x[i] + k + 1;
        xx[xn++] = x[i] - k + 1;
        xx[xn++] = x[i] + k - 1;
    } 
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        yy[yn++] = y[i];
        yy[yn++] = y[i] - k;
        yy[yn++] = y[i] + k;
        yy[yn++] = y[i] - 1;
        yy[yn++] = y[i] + 1;
        yy[yn++] = y[i] - k - 1;
        yy[yn++] = y[i] + k + 1;
        yy[yn++] = y[i] - k + 1;
        yy[yn++] = y[i] + k - 1;
    } 

    for (int i = 0 ; i < xn; ++i) {
        for (int j = 0; j < yn; ++j) {            
            all.push_back( CalcH(xx[i], yy[j]) );
        }
    }
    sort(all.begin(), all.end());
    cout << (unique(all.begin(), all.end()) - all.begin()) << endl;
    
    return 0;
}
