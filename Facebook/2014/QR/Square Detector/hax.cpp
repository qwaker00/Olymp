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


int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        int n;
        string s[22];
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> s[i];

        cout << n << endl;
        for (int i = 0; i < n; ++i) cout << s[i] << endl;

        bool found = false;
        bool answer = false;
        for (int i = 0; i < n && !found; ++i)
            for (int j = 0; j < n && !found; ++j)
                if (s[i][j] == '#') {
                    found = true;

                    for (int k = 0; i + k < n && j + k < n; ++k) {
                        bool good = true;
                        for (int l = 0; l <= k; ++l) {
                            if (s[i + k][j + l] != '#') {
                                good = false;
                                break;
                            }
                            if (s[i + l][j + k] != '#') {
                                good = false;
                                break;
                            }
                        }
                        if (!good) break;
                        for (int l = 0; l <= k; ++l) {
                            s[i + k][j + l] = '.';
                            s[i + l][j + k] = '.';
                        }
                    }
                    answer = true;
                    for (int k = 0; k < n; ++k) for (int l = 0; l < n; ++l) if (s[k][l] == '#') answer = false;
                }
        printf("Case #%d: %s\n", __it, answer ? "YES" : "NO");
    }    
    
    return 0;
}
