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
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;
set< pair<string, int> > all;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    
    int d[111];
    for (int i = 1; i < 1000; ++i) {
        int x = i, dn = 0, mx = 0;
        while (x > 0) {
            d[dn++] = x % 10;
            x /= 10;
            if (d[dn - 1] > mx) mx = d[dn - 1];
        }
        for (int base = mx + 1; base <= i + 1; ++base) {
            int x = i, dn = 0;
            while (x > 0) {
                d[dn++] = x % 10;
                x /= 10;
            }
            d[dn] = 0;
            ++d[0];
            for (int k = 0; k < dn; ++k) if (d[k] == base) {
                d[k] = 0;
                ++d[k + 1];
                if (k + 1 == dn) ++dn;
            }
            char buf[44];
            int wr = 0;
            for (int k = dn - 1; k >= 0; k--) wr += sprintf(buf + wr, "%d", d[k]);
            buf[wr] = 0;

            pair<string, int> p(buf, i);
            all.insert(p);
        }
    }

    for (set<pair<string, int> >::iterator i = all.begin(); i != all.end(); ++i)
        printf("%s <- %d\n", i->first.c_str(), i->second);
        
    return 0;
}
