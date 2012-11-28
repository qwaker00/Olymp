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

const int N = 222;
int A[N * N];
int n;

int main() {
    freopen("loudcats.in", "r", stdin);
    freopen("loudcats.out", "w", stdout);
    
    int n, m; LL a;
    cin >> n >> m; cin >> a;
    LL ans = 0;

    for (int i = 1; i <= n*m; ++i) {
        cin >> A[i];
    } 
    for (int i = 1; i <= n*m; ++i) {
        if (i + m <= n * m && A[i] * 2 < A[i + m]) ans += a;
    }

    cout << ans << endl;

    return 0;
}
