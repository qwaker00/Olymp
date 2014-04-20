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

char s[1111111];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    gets(s);    
    int l = strlen(s), ans = 0;

    for (int i = 0; i < l;) {
        if (s[i] == '(') {
            ++i;
            while (i < l && (s[i] == ' ' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ) ++i;
            if (s[i] == ')') {
                ++i;
            } else {
                ++ans;
            }
        } else {
            if (s[i] == '(' || s[i] == ')') ++ans;
            ++i;
        }
    }
    cout << ans << endl;
    
    return 0;
}
