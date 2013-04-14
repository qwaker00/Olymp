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

#define L 1111111

char s[L], ss[L];
int z[L], l;

int main() {
    freopen("decimal.in", "r", stdin);
    freopen("decimal.out", "w", stdout);
    
    char c1 = getchar();
    char c2 = getchar();
    gets(s);
    l = strlen(s);
    memcpy(ss, s, l);
    reverse(ss, ss + l);
    
    z[0] = 0;
    for (int i = 1, le = 0, ri = 0; i < l; ++i) {
        if (i <= ri) z[i] = min(z[i - le], ri - i + 1);else z[i] = 0;
        while (i + z[i] < l && ss[i + z[i]] == ss[z[i]]) ++z[i];
        if (i + z[i] - 1 > ri) {
            le = i;
            ri = i + z[i] - 1;
        }
    }

    int ansi = 0;
    int ansj = l;
    for (int i = 1; i < l; ++i) {
        if (ansj > l - z[i]) {
            ansj = l - z[i];
            ansi = l - i - z[i];
        }
    }

    char ch = 0;
    swap(s[ansi], ch);
    printf("%c%c%s(", c1, c2, s);
    swap(s[ansi], ch);
    swap(s[ansj], ch);
    printf("%s)\n", s + ansi);
//    cerr << clock() << endl;    
    
    return 0;
}
