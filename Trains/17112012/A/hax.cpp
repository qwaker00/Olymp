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

char a[1111111], b[1111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    gets(a);
    gets(b);
    puts( strlen(a) >= strlen(b) ? "go" : "no");
    
    return 0;
}