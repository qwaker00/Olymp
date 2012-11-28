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

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct Tp {
    int x, y, yy;
    Tp(int x = 0, int y = 0, int yy = 0):x(x), y(y), yy(yy) { };  
} ;

vector<Tp> v1;
vector<Tp> v2;
int n, x, y, xx, yy;
LL ans = 0;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> xx >> yy;
        if (x == xx) {
            v1.push_back(Tp(x, min(y, yy), max(yy, y)));
        } else
        if (y == yy) {
            v2.push_back(Tp(y, min(x, xx), max(x, xx)));
        }
    }

    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v1.size(); ++j) if (v1[i].x < v1[j].x) {
            int hi = min(v1[i].yy, v1[j].yy);
            int lo = max(v1[i].y, v1[j].y);
            if (hi <= lo) continue;

            int sum = 0;
            for (int k = 0; k < v2.size(); ++k)
                if (v2[k].y <= v1[i].x && v2[k].yy >= v1[j].x && v2[k].x <= hi && v2[k].x >= lo)
                    ++sum;
            ans += LL(sum) * (sum - 1);
        } 
    }                     
    cout << ans / 2 << endl;
        
    return 0;
}
