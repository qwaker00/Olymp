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
string s;
vector<LL> ans[22];
//vector<LL> all;

bool Div(const char * s, int n, LL x) {
    static int was[33];
    static int dd[33];
    for (int it = 0; it < 500; ++it) {
        memset(was, -1, sizeof(was));
        for (int i = 0; i <= 9; ++i) dd[i] = i;
        int left = 10, d;
        LL xx = 0;
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if (was[ch] == -1) {
                if (i == 0) {
                    int p = 1 + rand() % (left - 1);
                    d = dd[p];
                    dd[p] = dd[--left];
                } else {
                    int p = rand() % left;
                    d = dd[p];
                    dd[p] = dd[--left];
                }
            
                was[ch] = d;    
            } else {
                d = was[ch];
            }
            xx = xx * 10 + d;
        }
        if (xx % x) return false;
    }
    return true;
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    LL x = 9;
    for (int i = 1; i <= 14; ++i) {
        int end = int(sqrt(x)) + 1;
        for (int j = 1; j <= end; ++j) {
            if (x % j == 0) {
                ans[i].push_back(j);
//                all.push_back(j);
                if (LL(j) * j != x) {
                    ans[i].push_back(x / j);
//                    all.push_back(x / j);
                }
            }
        }
        sort(ans[i].begin(), ans[i].end());
//        cerr << i << " " << ans[i].size() << endl;
        x = x * 10 + 9;
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int l = s.length();
        cout << "Case " << (i + 1) << ":";
        for (int j = 0; j < ans[l].size(); ++j) {
            if (Div(s.c_str(), l, ans[l][j])) {
                cout << " " << ans[l][j];
            }
        } 
        cout << endl;
    }


//    sort(all.begin(), all.end());
//    all.erase(unique(all.begin(), all.end()), all.end());

//    cerr << all.size() << endl;
    cerr << clock() << endl;
    return 0;
}
