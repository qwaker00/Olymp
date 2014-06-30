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

char s[1000111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int n;
    scanf("%d\n", &n);
    while (n--) {
        gets(s);
        int bal = 0;
        int ans = 0;
        for (int i = 0; s[i]; ++i) {
            if (s[i] == '<') ++bal;else --bal;
            if (bal < 0) break;
            if (bal == 0) ans = i + 1;
        }
        printf("%d\n", ans);
    }    
    
    return 0;
}
