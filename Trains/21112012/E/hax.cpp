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


int cnt[1111111];
int was[1111111];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int IT = 0;
    int ans = 1;
    for (int i = 0; i < 2010; i++) {
        IT++;
        int x = i;
        int cnt = 0;
        while (was[x] != IT) {
            was[x] = IT;
            x = (x * x) % 2010;
            cnt++;
        } 
        ans = ans * cnt / __gcd(ans, cnt);
//        cerr << cnt << endl;
//        cerr << x << endl;
//        cnt[x]++;
    }
    cerr << ans << endl;
    
    return 0;
}
