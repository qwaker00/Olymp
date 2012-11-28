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

#define N 111111

char s[111111];
int n;

int main() {
    freopen("headshot.in", "r", stdin);
    freopen("headshot.out", "w", stdout);

    gets(s);
    n = strlen(s);
    int zeraft = 0;
    int zer = 0;
    for (int i = 0; i  + 1 < n; i++) if (s[i] == '0' && s[i + 1] == '0') zeraft++;
    if (s[n - 1] == '0' && s[0] == '0') zeraft++;
    for (int i = 0; i < n; i++) if (s[i] == '0') zer++;


    if (zeraft * n  == zer * zer) {
        puts("EQUAL");
    }else
    if (zeraft * n > zer * zer) {
        puts("SHOOT");
    }else {
        puts("ROTATE");
    }

    return 0;
}
                      