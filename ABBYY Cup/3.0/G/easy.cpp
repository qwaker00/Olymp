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
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    gets(s);
    int l = strlen(s);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", p[i], &pl[i], &pr[i]);
        ps[i] = string(p[i]);
    }

    set<string> ans;
    for (int i = 0; i < l; ++i) {
        for (int j = i; j < l; ++j) {
            char ch = 0;
            swap(ch, s[j + 1]);
            string str(s + i);
            swap(ch, s[j + 1]);

            bool good = true;
            for (int k = 0; k < n; ++k) {
                int cnt = 0;
                for (int kk = 0; kk <= (int)ps[k].size() - (int)str.size(); ++kk) {
                    if (ps[k].substr(kk, str.size()) == str) ++cnt;
                }
                if (cnt < pl[k] || cnt > pr[k]) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ans.insert(str);
            }
        }
    }
    cout << ans.size() << endl;
    
    return 0;
}
