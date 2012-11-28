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

int n;
set<int> s;
multiset<int> ms;

char w[33];

string anses[4] = {"neither", "homo", "hetero", "both"};

int main() {
    freopen("homo.in", "r", stdin);
    freopen("homo.out", "w", stdout);
    
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%s%d", w, &x);
        if (w[0] == 'i') {
            ms.insert(x);
            s.insert(x);
        } else {
            multiset<int>::iterator it = ms.find(x);
            if (it != ms.end()) {
                ms.erase(it);
                if (ms.find(x) == ms.end()) s.erase(x);
            }
        }
        //cerr << s.size() << " " << ms.size() << endl;

        int ans = 0;
        if (s.size() < ms.size()) ans += 1;
        if (s.size() > 1) ans += 2;
        puts(anses[ans].c_str());
    }

    return 0;
}
