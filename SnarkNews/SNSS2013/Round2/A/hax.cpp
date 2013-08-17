#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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


string s1, s2;
int pn1, pn2, p1[1111], p2[1111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> s1;
    cin >> s2;


    int n = s1.length();

    pn1 = pn2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 'V' && s1[i] != s2[i]) p1[pn1++] = i;
        if (s2[i] == 'V' && s1[i] != s2[i]) p2[pn2++] = i;
    }
    int ans1 = 0;
    for (int i = 0; i < pn1; ++i) ans1 = max(ans1, abs(p1[i] - p2[i]));

    pn1 = pn2 = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == 'W' && s1[i] != s2[i]) p1[pn1++] = i;
        if (s2[i] == 'W' && s1[i] != s2[i]) p2[pn2++] = i;
    }
    int ans2 = 0;
    for (int i = 0; i < pn1; ++i) ans2 = max(ans2, abs(p1[i] - p2[i]));

    cout << max(ans1, ans2) << endl;        
    
    return 0;
}
