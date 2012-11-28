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

const int N = 20002;

int w, h;

vector< pair<int, int> > a[N];

int main() {
    freopen("circles.in", "r", stdin);
    freopen("circles.out", "w", stdout);
    
    int n;
    cin >> w >> h >> n;
    while (n--) {
        int x, y, r;
        cin >> x >> y >> r;

        int r2 = r * r;

        int can = r;
        int dy = 0;
        for (int i = y; i < h; ++i) {
            while (can >= 0 && can * can + dy * dy > r2) --can;
            if (can < 0) break;

            a[i].push_back(make_pair(max(x - can, 0), -1));
            a[i].push_back(make_pair(min(x + can + 1, w), 1));

            ++dy; 
        }

        can = r;
        dy = 1;
        for (int i = y - 1; i >= 0; --i) {
            while (can >= 0 && can * can + dy * dy > r2) --can;
            if (can < 0) break;

            a[i].push_back(make_pair(max(x - can, 0), -1));
            a[i].push_back(make_pair(min(x + can + 1, w), 1));

            ++dy; 
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        sort(a[i].begin(), a[i].end());
        
        int p = 0, st = 0;
        for (int j = 0; j < w; ++j) {
            while (p < a[i].size() && a[i][p].first == j) {
                st += a[i][p].second;
                ++p;
            }
            if (st == 0) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
