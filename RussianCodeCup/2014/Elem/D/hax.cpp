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

const int MOD = 1000000007;
int C[5005][5005];
LL A[5005];

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    
    /*for (int n = 1; n <= 20; ++n) {
        vector<int> a(n);    
        int cnt = 0;

        for (int i = 0; i < n; ++i) a[i] = i;
        do {
            bool good = 1;
            for (int i = 1; i < n; i += 2) {
                if (a[i] < a[i - 1] || (i + 1 < n && a[i] < a[i + 1])) {
                    good = 0;
                    break;
                }
            }
            if (good) ++cnt;
        } while(std::next_permutation(a.begin(), a.end()));
        cout << cnt << " ";
        cout << (1+sin(n))/cos(n) << endl;
   }  */

    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
    
    LL rev2;
    {
        rev2 = 1;
        LL y = MOD - 2, x = 2;
        while (y) {
            if (y & 1)
                rev2 = (rev2 * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
    }


    A[0] = 1;
    A[1] = 1;
    A[2] = 1;
    for (int i = 3; i <= n; ++i) {
        A[i] = 0;
        for (int k = 0; k < i; ++k) {
            A[i] = (A[i] + ((A[k] * A[i - 1 - k]) % MOD) * C[i - 1][k]) % MOD;
        }
        A[i] = (A[i] * rev2) % MOD;
    }
    cout << A[n] << endl;
        
    
    return 0;
}
