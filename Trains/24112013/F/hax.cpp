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

/*int g[311];

void rec(int x, int i, set<int>& v, int xr) {
    if (stn > 0 && x > st[stn - 1]) {
        v.insert(g[x] ^ xr);
    }
    for (int j = i + 1; j + j < x; ++j) {
        st[stn++] = j;
        rec(x - j, j, v, xr ^ g[ j ]);
        --stn;
    }
} */

int G[9] = {0, 0, 0, 1, 0, 2, 3, 4, 0};
int st[311];
int stn;

inline int g(int x) {
    if (x <= 8) return G[x];
    return x - 4;
}

bool recfirst(int x, int i, int xr) {
    if (stn > 0 && x > st[stn - 1] && (xr ^ g(x)) == 0) {
        st[stn++] = x;
        return true;
    }
    for (int j = i + 1; j + j < x; ++j) {
        st[stn++] = j;
        if (recfirst(x - j, j, xr ^ g(j) )) return true;
        --stn;
    }
    return false;    
}

string ans[333];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    for (int n = 1; n <= 300; ++n) {
        stringstream out;
        
//        cin >> n;
        if (g(n) == 0) {
            out << "lose\\n";
        } else {
            out << "win\\n";
            stn = 0;
            recfirst(n, 0, 0);
            for (int i = 0; i < stn; ++i)  out << st[i] << " ";
            out << "\\n";
        }
        out.flush();

        cout << '"' << out.str() << "\",";
        cerr << n << ": " << clock() << endl;
    }
    
    return 0;
}
