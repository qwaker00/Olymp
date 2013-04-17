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

char s[111];

bool palindr(const string& s) {
    int l = s.length();
    for (int i = 0; i + i < l; ++i) {
        if (s[i] != s[l - i - 1])
            return false;
    }
    return true;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);


    vector< pair<int, string> > all[1024];
    
    for (int i = 0; i < 255; ++i)
        for (int j = 0; j < 255; ++j) {
            int l = sprintf(s, "%u%u", i, j);

            int msk = 0;
            for (int k = 0; k < l; ++k) msk |= (1 << (s[k] - '0'));

            all[msk].push_back(make_pair(i * 256 + j, s));
        }

    int n;
    cin >> n;
    int mask = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mask |= (1 << x);
    }


//    for (int mask = 1; mask < 1024; ++mask) {

    vector< pair<int, int> > ans;

    for (int sm = mask; sm > 0; sm = (sm - 1) & mask)
        for (int i = 0; i < all[sm].size(); ++i)
            for (int sm2 = sm; sm2 > 0; sm2 = (sm2 - 1) & sm) {
                int sm3 = (mask ^ sm) | sm2;
                for (int j = 0; j < all[sm3].size(); ++j) {
                    if (palindr(all[sm][i].second + all[sm3][j].second)) {
                        ans.push_back(make_pair(all[sm][i].first, all[sm3][i].first));
                    }
                }
            }

        cout << ans.size() << endl;
        for (int i =0; i < ans.size(); ++i) {
            cout << (ans[i].first >>8) << "."  << (ans[i].first & 255) << "."
                 << (ans[i].second >> 8) << "."  << (ans[i].first & 255) << endl;
        }
  //  }
      cerr << clock() << endl;  

    return 0;
}
