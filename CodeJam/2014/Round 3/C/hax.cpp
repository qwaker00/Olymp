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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    int T;
    cin >> T;
    for (int __it = 1; __it <= T; __it++) {
        
        int n;
        cin >> n;

        vector<int> good;
        good.reserve(1 << n);
        for (int i = 0; i < (1 << n); ++i) good.push_back(i);
        map<int, int> ids;
        int idc = 0;

        for (int _i = 0; _i < n; ++_i) {
            string s;
            int x;
            cin >> s >> x;

            if (x != 0) {
                if (ids.find(x) == ids.end()) ids[x] = idc++;
            } else {
                ++idc;
            }

            if (s == "E") {
                if (x != 0) {
                    int j = 0;
                    int xi = ids[x];
                    for (int i = 0; i < (int)good.size(); ++i)
                        if (!(good[i] & (1 << xi))) {
                            good[j++] = good[i] ^ (1 << xi);
                        }
                    good.erase(good.begin() + j, good.end());
                 } else {
                    vector<int> newg; 
                    for (int i = 0; i < (int)good.size(); ++i) {
                        for (int j = 0; j < n; ++j) if (!(good[i] & (1 << j))) {
                            newg.push_back(good[i] ^ (1 << j));
                        }
                    }
                    sort(newg.begin(), newg.end());
                    newg.erase(unique(newg.begin(), newg.end()), newg.end());
                    good = std::move(newg);
                 }
            } else {
                if (x != 0) {
                    int j = 0;
                    int xi = ids[x];
                    for (int i = 0; i < (int)good.size(); ++i)
                        if (good[i] & (1 << xi)) {
                            good[j++] = good[i] ^ (1 << xi);
                        }
                    good.erase(good.begin() + j, good.end());
                 } else {
                    vector<int> newg; 
                    for (int i = 0; i < (int)good.size(); ++i) {
                        for (int j = 0; j < n; ++j) if (good[i] & (1 << j)) {
                            newg.push_back(good[i] ^ (1 << j));
                        }
                    }
                    sort(newg.begin(), newg.end());
                    newg.erase(unique(newg.begin(), newg.end()), newg.end());
                    good = std::move(newg);
                 }
            }
        }
        cout << "Case #" << __it << ": ";

        if (!good.size()) {
            cout << "CRIME TIME" << endl;
        } else {
            int ans = 1e9;
            for (int i = 0; i < (int)good.size(); ++i) {
                int x = good[i], c = 0;
                while (x) {
                    ++c;
                    x &= x - 1;
                }
                if (c < ans) ans = c;
            }
            cout << ans << endl;
        }
    }
    
    return 0;
}
