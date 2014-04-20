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

int a[111111], an, c[111111];
char s[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    gets(s);
    int l = strlen(s);

    for (int i = 0; i < l; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            a[an] = s[i];
            c[an] = 1;
            ++an;
        } else
            ++c[an -  1];
    }

    int mi = 0;
    int ma = 0;
    vector<int> ans;
    ans.push_back(0);
    for (int i = 0; i < an; ++i) {
        if (a[i] == '>') {
            for (int j = 0; j + 1 < c[i]; ++j) {
                 ans.push_back(ans.back() - 1);
                 if (ans.back() < mi) mi = ans.back();
                 if (ans.back() > ma) ma= ans.back();
            }
            if (ans.back() > mi) ans.push_back(mi); else ans.push_back(ans.back() - 1);
            if (ans.back() < mi) mi = ans.back();
            if (ans.back() > ma) ma= ans.back();
        } else {
            for (int j = 0; j + 1 < c[i]; ++j) {
                 ans.push_back(ans.back() + 1);
                 if (ans.back() < mi) mi = ans.back();
                 if (ans.back() > ma) ma= ans.back();
            }
            if (ans.back() < ma) ans.push_back(ma); else ans.push_back(ans.back() + 1);
            if (ans.back() < mi) mi = ans.back();
            if (ans.back() > ma) ma= ans.back();
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i] - mi);
    }

    return 0;
}
