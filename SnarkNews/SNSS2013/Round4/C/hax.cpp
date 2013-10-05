#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

string Map[33];
int size = 0, n, m;

void dfs(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (Map[x][y] == '.') return;
    if (Map[x][y] == '*') return;
    Map[x][y] = '.';
    ++size;
    dfs(x - 1, y - 1);
    dfs(x, y - 1);
    dfs(x + 1, y - 1);
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
    dfs(x, y + 1);
    dfs(x - 1, y + 1);
    dfs(x - 1, y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> Map[i];
    }

    int ans1 = 0, ans2 = 0;
    if (n > 1) {
        for (int i = 0; i < m; ++i) {
            if (Map[n - 2][i] != '.') {
                dfs(n - 2, i);
                ++ans1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 3 < m; ++j) {
            if (Map[i][j] == '[' && Map[i][j + 1] == ']' &&
                Map[i][j + 2] == '[' && Map[i][j + 3] == ']')
                {
                    size = 0;
                    dfs(i, j);
                    if (size == 4) {
                        ++ans2;
                    }
                }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}
