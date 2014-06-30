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

LL solve() {
    int n;
    vector< vector<pair<char, int> > > gg;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        vector< pair<char, int> > g;
        for (int i = 0; i < s.length(); ++i) {
            if (i == 0 || s[i] != s[i - 1]) {
                g.push_back(make_pair(s[i], 1));
            } else {
                ++g.back().second;
            }
        }
        gg.push_back(g);
    }

    for (int i = 1; i < gg.size(); ++i) {
        if (gg[i].size() != gg[0].size())
            return -1;
        for (int j = 0; j < gg[0].size(); ++j)
            if (gg[i][j].first != gg[0][j].first)
                return -1;
    }
    LL ans = 0;
    for (int i = 0; i < gg[0].size(); ++i) {
        vector<int> v;
        for (int j = 0; j < gg.size(); ++j) v.push_back(gg[j][i].second);
        sort(v.begin(), v.end());

        LL subans = 0, submin = 1e18;
        for (int cc = 0; cc <= 100; ++cc) {
            subans = 0;
            for (int j = 0; j < gg.size(); ++j) subans += abs(cc - gg[j][i].second);
            submin= min(submin, subans);
        }
        ans += submin;
    }
    return ans;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;    
    for (int __it = 1; __it <= T; ++__it) {
        cout << "Case #" << __it << ": ";        
        LL t = solve();
        if (t == -1)
            cout << "Fegla Won";
        else
            cout << t;
        cout << endl;
    }
    
    return 0;
}
