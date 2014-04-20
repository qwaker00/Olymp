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

char s[111][111];
int pi[13], pj[13], pv[13], pn = 0, was[14];

int cnt = 0;

void rec(int i) {
    if (i == pn) {
        bool good = 
            pv[0] + pv[2] + pv[5] + pv[7] == 26 &&
            pv[0] + pv[3] + pv[6] + pv[10] == 26 &&
            pv[1] + pv[2] + pv[3] + pv[4] == 26 &&
            pv[7] + pv[8] + pv[9] + pv[10] == 26 &&
            pv[1] + pv[5] + pv[8] + pv[11] == 26 &&
            pv[4] + pv[6] + pv[9] + pv[11] == 26;

/*        if (pv[0] == 6 && pv[4] == 12) {
            cerr << pv[0] + pv[2] + pv[5] + pv[7] << " "
                 << pv[0] + pv[3] + pv[6] + pv[10] << " "
                 << pv[1] + pv[2] + pv[3] + pv[4] << " "
                 << pv[7] + pv[8] + pv[9] + pv[10] << " "
                 << pv[1] + pv[5] + pv[8] + pv[11] << " "
                 << pv[4] + pv[6] + pv[9] + pv[11] << endl;            
        }
*/
        if (good) {
            for (int i = 0; i < 5; ++i) {
                puts(s[i]);
            }
            exit(0);
        }
        return;    
    }
    if (pv[i] != 0) {
        rec(i + 1);
        return;
    }
    for (int j = 1; j <= 12; ++j) if (!was[j]) {
        pv[i] = j;
        was[j] = true;
        s[ pi[i] ][ pj[i] ] = pv[i] + 'A' - 1;

        if (!(pv[0] + pv[2] + pv[5] + pv[7] > 26 ||
            pv[0] + pv[3] + pv[6] + pv[10] > 26 ||
            pv[1] + pv[2] + pv[3] + pv[4] > 26 ||
            pv[7] + pv[8] + pv[9] + pv[10] > 26 ||
            pv[1] + pv[5] + pv[8] + pv[11] > 26 ||
            pv[4] + pv[6] + pv[9] + pv[11] > 26)
           )
            {
                rec(i + 1);
            }

        pv[i] = 0;
        was[j] = false;
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    for (int i = 0; i < 5; ++i) {
        gets(s[i]);
        for (int j = 0; j < 9; ++j) {
            if (s[i][j] == 'x') {
                pi[pn] = i;
                pj[pn] = j;
                pv[pn] = 0;
                ++pn;
            } else
            if (s[i][j] >= 'A') {
                pi[pn] = i;
                pj[pn] = j;
                pv[pn] = s[i][j] - 'A' + 1;
                was[pv[pn]] = true;
                ++pn;
            }
        }
    }

    rec(0);
    
    return 0;
}
