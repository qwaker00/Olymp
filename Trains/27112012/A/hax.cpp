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

const int N = 111;

char w[N][N][N];
bool u[N][N];

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    int n, m, k;
    cin >> k >> n >> m;
    cin.ignore();

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) gets(w[i][j]); 
    } 

    int ans = 0;
    for (int x1 = 0; x1 < n; ++x1)
        for (int y1 = 0; y1 < m; ++y1)
            if (!u[x1][y1]) {
                u[x1][y1] = true;
                ++ans;

                for (int x2 = x1; x2 < n; ++x2)
                    for (int y2 = 0; y2 < m; ++y2)
                        if (!u[x2][y2]) {
                            bool cool = true;
                            for (int i = 0; i < k; ++i)
                                if (w[i][x1][y1] != w[i][x2][y2]) {
                                    cool = false;
                                    break;
                                }
                            if (cool) u[x2][y2] = true;
                        }
            }
    
    cout << ans << endl;
        

    return 0;
}
