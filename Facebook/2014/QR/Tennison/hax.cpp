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
//typedef long long LL;
//typedef unsigned long long ULL;
//typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

//LD C[211][211], PSun[211][211], P[211][211], PW[211], PL[211], PRW[211], PRL[211];
LD F[66][66][66][66];

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    cerr << sizeof(F) << endl;

/*    for (int i = 0; i <= 210; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
*/

    cerr.precision(10);
    cerr << fixed;
    cout.precision(6);
    cout << fixed;

    int T;
    cin >> T;    
    for (int __it = 1; __it <= T; ++__it) {
        int K;
        LD ps, pr, pi, pu, pw, pd, pl;
        cin >> K >> ps >> pr >> pi >> pu >> pw >> pd >> pl;

/*        PW[0] = PRW[0] = PL[0] = PRL[0] = 1;
        for (int i = 1; i <= K; ++i) {
            PW[i] = PW[i - 1] * pw;
            PRW[i] = PRW[i - 1] * (1 - pw);
            PL[i] = PL[i - 1] * pl;
            PRL[i] = PRL[i - 1] * (1 - pl);
        }                           
        for (int i = 0; i <= K; ++i)
            for (int j = 0; j <= K; ++j) {
                PSun[i][j] = 0;
                for (int ii = 0; ii <= i; ++ii)
                for (int jj = 0; jj <= j; ++jj)
                {
                    LD pss = pi + pu * ii - pd * jj;
                    if (pss < 0) pss = 0;
                    if (pss > 1) pss = 1;
                    PSun[i][j] += pss * C[i][ii] * PW[ii] * PRW[i - ii] * C[j][jj] * PL[jj] * PRL[j - jj];
               }
            }
*/
        memset(F, 0, sizeof(F));
        F[0][0][0][0] = 1.;   
        for (int ij = 0; ij < K + K; ++ij) {
            for (int j = 0; j < K; ++j) {
                int i = ij - j;
                if (i >= K) continue;

                for (int ii = 0; ii <= i; ++ii)
                for (int jj = 0; jj <= j; ++jj) {
                    LD psun = max(LD(0.), min(LD(1.), pi + ii * pu - jj * pd)); 
                    LD pwin = psun * (ps - pr) + pr;
                    F[i + 1][j][ii + 1][jj] += F[i][j][ii][jj] * pwin * pw;
                    F[i + 1][j][ii][jj]     += F[i][j][ii][jj] * pwin * (1 - pw);
                    F[i][j + 1][ii][jj + 1] += F[i][j][ii][jj] * (1. - pwin) * pl;
                    F[i][j + 1][ii][jj]     += F[i][j][ii][jj] * (1. - pwin) * (1. - pl);
                }
            }
        }
        LD ans = 0;
        for (int i = 0; i < K; ++i) 
            for (int ii = 0; ii <= K; ++ii)
            for (int jj = 0; jj <= i; ++jj)
                ans += F[K][i][ii][jj];
        cout << "Case #" << __it << ": " << ans << endl;
    }
    return 0;
}
