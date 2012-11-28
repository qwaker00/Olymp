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

vector<int> g[111111];
int ans[111111];
int n, x;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        g[x].push_back(i);
    }

    int it = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = (int)g[i].size() - 1; j >= 0; j --) {
            ans[g[i][j]] = ++it;
        }
    }

    for (int i =0 ; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
