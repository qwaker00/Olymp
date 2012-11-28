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

string s;
int n, a, c;
LL ans1, ans2, ans3, balk = 0;

int main() {
    freopen("flat.in", "r", stdin);
    freopen("flat.out", "w", stdout);

    cin >> n >> c;
    for (int i = 0; i< n; i++) {
        cin >> a >> s;
        ans1 += a;
        if (s == "bedroom") ans2 += a;
        if (s == "balcony") balk += a;
    }
    cout.precision(2);
    cout << fixed;
    cout << ans1 << endl << ans2 << endl << LD(ans1 - 0.5 * balk) * c << endl;

    
    return 0;
}
