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

bool Cmp(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}
map<string, string> country;
map<string, int> cnt;
map<string, int> cntCountry;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    pair<int, string> ans = make_pair(-1, "");
    pair<int, string> ansCountry = make_pair(-1, "");
    string s1, s2;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        country[s1] = s2;
        cnt[s1] = 0;
        cntCountry[s2] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> s1;
        int t = ++cnt[s1];
        if (Cmp(make_pair(t, s1), ans)) {
            ans = make_pair(t, s1);
        }
        
        t = ++cntCountry[country[s1]];
        if (Cmp(make_pair(t, country[s1]), ansCountry)) {
            ansCountry = make_pair(t, country[s1]);
        }
    }

    cout << ansCountry.second << endl;
    cout << ans.second << endl;

    return 0;
}
