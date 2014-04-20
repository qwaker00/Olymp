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

const LL M = 1000000007;

long long ans = 0;
int out[111111], in[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &out[i], &in[i]);
    }
    int killed = 0;
    ans = 1;
    sort(in, in + n);
    sort(out, out + n);
    for (int i = n - 1, j = n; i >= 0;) {
        while (j > 0 && in[j - 1] > out[i]) --j;
        int k = i;
        while (k > 0 && out[k - 1] == out[i]) --k;

        int vars = n - j - killed;
        if (vars == 0) {
            // Z - z - z
        } else {
            int rv = i - k + 1;  
            if (vars >= rv) {
                while (rv > 0) {
                    ans = (ans * vars) % M;
                    ++killed;
                    --rv;
                    --vars;
                }
            } else {
                while (vars > 0) {
                    ans = (ans * rv) % M;
                    ++killed;
                    --vars;
                    --rv;
                }
            }
        }
        i = k - 1;        
    }
    cout << ans << endl;
    
    return 0;
}
