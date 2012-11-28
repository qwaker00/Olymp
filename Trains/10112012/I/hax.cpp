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

#define N 222

int IT = 0, k[N], pr[N], to[N][N], ans = 0;
int was[N];
int n;

bool kuhn(int x) {
    if (was[x] == IT) return false;
    was[x] = IT;
    for (int j = 0; j < k[x]; ++j)
        if (pr[ to[x][j] ] == -1 || kuhn(pr[to[x][j]])) {
            pr[to[x][j]] = x;
            return true;
        }
    return false;
}

void print(int x) {
   printf("%d ", x);
   for (int j = 1; j <= n; j++) if (pr[j] == x)  {
       print(j);
       break;
   }    
}


int main() {
    freopen("inspection.in", "r", stdin);
    freopen("inspection.out", "w", stdout);

    cin >> n;
    int m = 0;
    for (int i =  1; i <= n; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) cin >> to[i][j];
        m += k[i];
    }

    memset(pr, -1, sizeof(pr));
    for (int i = 1; i <= n; i++) {
        IT++;
        if (kuhn(i))
            ++ans;
    }

    cout << m - ans << endl;
    for (int i = 1; i <= n; i++) if (pr[i] == -1) {
        print(i);
        puts("");
    }
    
    return 0;
}
