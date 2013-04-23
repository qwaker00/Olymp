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

char a[2111111], b[2111111];
int n, c[2][2];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d\n", &n);
    gets(a);
    gets(b);
    n += n;

    for (int i = 0; i < n; ++i) {
        ++c[a[i] - 48][b[i] - 48];
        
    }
   
    int cnta = 0;
    int cntb = 0;
    for (int i = 0; i < n; ++i) {
        if (c[1][1]) {
            --c[1][1];
            cnta += 1;
        } else
        if (c[1][0]) {
            --c[1][0];
            cnta += 1;
        } else
        if (c[0][1]) {
            --c[0][1];
        } else
            --c[0][0];

        if (c[1][1]) {
            --c[1][1];
            cntb += 1;
        } else
        if (c[0][1]) {
            --c[0][1];
            cntb += 1;
        } else
        if (c[1][0]) {
            --c[1][0];
        } else
            --c[0][0];
    }

    if (cnta > cntb) 
        puts("First");else
    if (cntb > cnta)
        puts("Second");else
        puts("Draw");
        
    return 0;
}
