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
int l;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    vector<LL> v;
    gets(s);
    char* p = strtok(s, "+");
    while (p) {
        v.push_back(atoi(p));
        p = strtok(0, "+");
    }

    LL s = 0;
    while (v.size() > 0 && v.back() == 1) {
        s += 1;
        v.pop_back();
    }
    if (v.size() == 0) {
        s += 1;
        v.push_back(s);
    } else {
        --v.back();
        s += 1;
        while (s) {
            v.push_back(min(s, v.back()));
            s -= v.back();
        }
    }

    cout << v[0];
    for (int i = 1; i < v.size(); ++i) {    
        cout << "+" << v[i];
    }
    puts("");
    
    return 0;
}
