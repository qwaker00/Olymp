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

const int N = 502;

int n;
struct cell {
    int x, y;

    cell(int ax = 0, int ay = 0) : x(ax), y(ay) {}

    bool operator <(const cell& A) const {
        return y < A.y;
    }
} a[N];

bool f[N][N * N];
bool inFirst[N];

int main() {
    freopen("equal-power.in", "r", stdin);
    freopen("equal-power.out", "w", stdout);
    
    int S = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].y;
        a[i].x = i;
        S += a[i].y;
    }
    sort(a, a + n);

    if (n == 1) {
        puts("-1");
        return 0;
    }
    if (n == 2) {
        if (a[0].y == a[1].y) {
            cout << a[0].y * 2 << endl;
            cout << 1 << endl << 1 << endl << 1 << endl << 2 << endl;
        } else {      
            puts("-1");
        }
        return 0;
    }



    int sum = 0;
    for (int i = 0; i + 2 < n; ++i) {
        if (i == 0) {
            f[0][0] = 1;
            f[0][ a[0].y ] = 1;
        } else {
            for (int j = 0; j <= sum; ++j)
                if (f[i - 1][j]) {
                    f[i][j] = 1;
                    f[i][j + a[i].y] = 1;
                }
        }      
        sum += a[i].y;

        int A = a[n - 1].y;
        int B = a[i + 1].y;

        int need = S - 3 * B + A;
        if (need < 0 || (need & 1)) continue;
        need >>= 1;
        if (need > sum) continue;

        if (f[i][need]) {
            cout << need + B * 2 << endl;
            int x = i;
            int y = need;
            inFirst[ a[i + 1].x ] = true;

            while (x) {
                if (f[x - 1][y]) {
                    x = x - 1;
                } else {
                    y -= a[x].y;
                    inFirst[ a[x].x ] = true;
                    x--;
                }
            }

            if (y) inFirst[ a[0].x ]  = true;

            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < n; ++i)
                if (inFirst[i]) cnt1++;
                else cnt2++;
            
            cout << cnt1 << endl;
            for (int i = 0; i < n; ++i)
                if (inFirst[i]) cout << i + 1 << " ";
            cout << endl; 

            cout << cnt2 << endl;
            for (int i = 0; i < n; ++i)
                if (!inFirst[i]) cout << i + 1 << " ";
            cout << endl;

            return 0;
        }

    }

    puts("-1");
    
    return 0;
}
