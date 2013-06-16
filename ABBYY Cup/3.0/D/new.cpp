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


#define MOD 1000000007 

int n, x;
int a[111];
int cnt[111];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);


    cin >> n;
//    for (int i = 0; i < n; ++i) a[i] = (i + 1) % n;
    for (int i = 0; i < n; ++i) a[i] = i;

    do {
        int c = 0;
        vector<char> was(n, false);
        for (int i = 0; i < n; ++i) {
            if (!was[i]) {
                int x = a[i];
                while (x != i) {
                    was[x] = true;
                    x = a[x];
                }
                was[x] = true;
                ++c;
            }
        }
        cnt[c]++;
    } while (next_permutation(a, a + n));
    for (int i = 1; i <= n; ++i) {
        cerr << i << ": " << cnt[i] << endl;
    }
    
    return 0;
}
