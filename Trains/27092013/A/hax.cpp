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


char s[111111];
int st[111111];
int back[111111];
int stn = 0;
int n;
int ansi = -1;
int ansj = 0;

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);

    
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        back[i] = -1;
        if (s[i] == '[' || s[i] == '(') {
            st[stn++] = i;
        } else {
            if (stn == 0) continue;
            int lst = s[st[stn - 1]];
            if (lst == '[' && s[i] == ']' || lst == '(' && s[i] == ')') {
                back[i] = st[stn - 1];
                if (back[i] > 0 && back[back[i] - 1] != -1) back[i] = back[back[i] - 1];
                if (i - back[i] > ansi - ansj) {
                    ansi = i;
                    ansj = back[i];
                }
                --stn;
            } else stn = 0;
        }
    }

    s[ansi + 1] = 0;
    puts(s + ansj);

    return 0;
}
