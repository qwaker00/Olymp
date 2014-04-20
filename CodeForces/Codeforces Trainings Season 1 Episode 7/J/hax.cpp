#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int n, ans = 0;
char s[55];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d\n%s", &n, s);

    int fr = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') {
            if (fr) {
                ++ans;
                fr = 1;
            } else {
                ++ans;
                fr = 0;
            }
        } else {
            if (fr) {
                ++ans;
                ++ans;
            } else
                ++ans;
            fr = 0;
            ++i;
        }
    }
    cout << ans << endl;
    
    return 0;
}
