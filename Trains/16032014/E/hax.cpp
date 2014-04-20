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

const int N = 222222;

int n;
char s[N];
int prevq[N], nextq[N];

const int M2 = 1000000007;
const int P = 37;
pair<ULL, unsigned> H[N], Hr[N];
pair<ULL, ULL> PP[N];

pair<ULL, unsigned> gethash(int l, int r) {
    if (r < l) return make_pair(0, 0);
    if (l == 0) return H[r];
    return make_pair(H[r].first - H[l - 1].first * PP[r - l + 1].first, (H[r].second + M2 - (H[l - 1].second * PP[r - l + 1].second) % M2) % M2);
}

pair<ULL, unsigned> gethashrev(int l, int r) {
    if (r < l) return make_pair(0, 0);
    if (r == n - 1) return Hr[l];
    return make_pair(Hr[l].first - Hr[r + 1].first * PP[r - l + 1].first, (Hr[l].second + M2 - (Hr[r + 1].second * PP[r - l + 1].second) % M2) % M2);
}

void precalchash(char * s, int n) {
    ULL h1 = 0;
    ULL h2 = 0; 
    for (int i = 0; i < n; ++i) {        
        h1 = h1 * P + s[i] - 'a' + 1;
        h2 = (h2 * P + s[i] - 'a' + 1) % M2;

        H[i].first = h1;
        H[i].second = h2;
    }

    h1 = 0;
    h2 = 0;
    for (int i = n - 1; i >= 0; --i) {        
        h1 = h1 * P + s[i] - 'a' + 1;
        h2 = (h2 * P + s[i] - 'a' + 1) % M2;

        Hr[i].first = h1;
        Hr[i].second = h2;
    }


    PP[0].first = PP[0].second = 1;
    for (int i = 1; i <= n; ++i) {
        PP[i].first = PP[i - 1].first * P;
        PP[i].second = (PP[i - 1].second * P) % M2;
    }
}

int main() {
    freopen("palindromes.in", "r", stdin);
    freopen("palindromes.out", "w", stdout);
    

    gets(s);
    n = strlen(s);


/*    cout.precision(20);
    cout << fixed;
    cerr.precision(20);
    cerr << fixed;

    LD rans = 0;
    for (int i = 0; i < n; ++i) {
        LD pp = 1;
        LD pans = -1;
        for (int j = 0; i + j < n && i - j >= 0; ++j) {
            pans += 2 * pp;
            if (i - j - 1 >= 0 && i + j + 1 < n) {
                if (s[i - j - 1] == '?' || s[i + j + 1] == '?') {
                    pp /= 26;
                } else if (s[i - j - 1] != s[i + j + 1]) break;
            }
        }
//        cerr << i << " " << pans << endl;
        rans += pans;
    }
    rans /= n;

//    cerr << rans << endl;

*/
    {
        int last = -1;
        for (int i = 0; i < n; ++i) {
            prevq[i] = last;
            if (s[i] == '?') last = i;
        }
        last = n;
        for (int i = n - 1; i >= 0; --i) {
            nextq[i] = last;
            if (s[i] == '?') last = i;
        }
    }

    precalchash(s, n);

    LD ans = 0;
    for (int i = 0; i < n; ++i) {
        LD pp = 1.;
        LD ansp = 0.;

        int iter = 0;
        int lastlen = 0;
        while (i - lastlen >= 0 && i + lastlen < n) {
            if (++iter > 20) break;
            int ll = prevq[i - lastlen];
            int rr = nextq[i + lastlen];
            int len = (i - ll < rr - i) ? i - ll : rr - i;

            if (gethash(i - len + 1, i - lastlen - 1) == gethashrev(i + lastlen + 1, i + len - 1)) {
                ansp += pp * (2 * (len - lastlen));
            } else {
                int left = lastlen;
                int right = len - 1;
                while (left < right) {
                    int center = (left + right + 1) / 2;
                    if ( gethash(i - center, i - lastlen - 1) == gethashrev(i + lastlen + 1, i + center) ) {
                        left = center;
                    } else {
                        right = center - 1;
                    }
                }
                ansp += pp * 2 * (left - lastlen + 1);
                break;
            }
            lastlen = len;
            pp *= LD(1) / 26;
        }
        ansp -= 1;
//        cerr << ansp << endl;
//        cout << i << " " << ansp << endl;

        ans += ansp;
    }
    ans /= n;

    cout.precision(20);
    cout << fixed << ans << endl;

/*    if (fabsl(rans - ans) > 1e-8) {
        cerr << "ERROR!!\n";
        while (1);
    }
*/
    
    return 0;
}
