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

const int L = 255555;
const int P = 31;
const int M = 1000000007;
char s1[L], s2[L];
int l1, l2;

ULL p1[L], p2[L];

pair<ULL, unsigned> hh[L];

int check(int center) {
    ULL H1 = 0, H2 = 0;
    int hn = 0;
    for (int i = 0; i < l1; ++i) {
        H1 = H1 * P + s1[i];
        H2 = (H2 * P + s1[i]) % M;
        if (i >= center) {
            H1 -= p1[center] * s1[i - center];
            H2 = (H2 + (M - p2[center]) * s1[i - center]) % M;
        }
        if (i >= center - 1) hh[hn++] = make_pair(H1, H2);
    }

    sort(hh, hh + hn);
    hh[hn] = make_pair(-1, -1);

    H1 = 0, H2 = 0;
    for (int i = 0; i < l2; ++i) {
        H1 = H1 * P + s2[i];
        H2 = (H2 * P + s2[i]) % M;
        if (i >= center) {
            H1 -= p1[center] * s2[i - center];
            H2 = (H2 + (M - p2[center]) * s2[i - center]) % M;
        }
        if (i >= center - 1) {
            pair<ULL, unsigned> tgt = make_pair(H1, H2);
            if (*lower_bound(hh, hh + hn, tgt) == tgt) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);    

    gets(s1);
    gets(s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    for (int i = 0; i < l1; ++i) s1[i] -= 'a' - 1;
    for (int i = 0; i < l2; ++i) s2[i] -= 'a' - 1;

    int ll = max(l1, l2);

    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i <= ll; ++i) {
        p1[i] = p1[i - 1] * P;
        p2[i] = (p2[i - 1] * P) % M;
    }

    int left = 0;
    int right = min(l1, l2);
    while (left < right) {
        int center = (left + right + 1) >> 1;
                    
        if (check(center) == -1)
            right = center - 1;
        else
            left = center;
    }

    if (!left)
        puts("0");
    else {
        char * f = s2 + check(left) + 1;        
        char * s = f - left;
        while (s < f) {
            putchar(*s + 'a' - 1);
            ++s;
        }
        puts("");
        printf("%d\n", left);
    }
    
    return 0;
}
