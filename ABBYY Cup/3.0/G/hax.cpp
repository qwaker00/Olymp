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


char s[55555];
char p[11][55555];
int pl[11], pr[11];
string ps[11];
int pref[55555];


template<typename TCharIter, typename TArray>
void kmp(const TCharIter& s, const TCharIter& end, TArray& p) {
    int length = end - s;
    p[0] = 0;
    for (int i = 1; i < length; ++i) {
        int& k = p[i] = p[i - 1];
        while (k > 0 && s[k] != s[i]) k = p[k - 1];
        if (s[k] == s[i]) ++k;else k = 0;
    }
}


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);


    gets(s);
    int l = strlen(s);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", p[i], &pl[i], &pr[i]);
        ps[i] = string(p[i]);
    }

    for (int i = 0; i < l; ++i) {
        vector<char> good(l, true);

        string ss(s + i);
        for (int j = 0; j < n; ++j) {
            string tg = ps[j] + "$" + ss;

            kmp(tg.c_str(), tg.c_str() + tg.length(), pref);

        }
    }
    
    return 0;
}
