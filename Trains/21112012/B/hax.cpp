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

const int N = 111111;

int n;
vector<int> g[N];
int kv = 0;

int wh[N];

char w[N];

int order[N];
bool canceled[N];


int main() {
    freopen("bureau.in", "r", stdin);
    freopen("bureau.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; ++i){
        scanf("%s", w);
        if (w[0] == 'c') {
            int x; scanf("%d", &x);
            g[ x ].push_back(i);
        }
        order[i] = n - i + 1;
    }


    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int x = order[i];
        for (int j = 0; j < g[x].size(); ++j)
            if (!canceled[ g[x][j] ]) {
                canceled[x] = true;
                break;
            }
        if (!canceled[x]) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);

    return 0;
}
