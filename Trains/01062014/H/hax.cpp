#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cassert>

using namespace std;
typedef long double LD;

int main() {
   // freopen(".in", "r", stdin);
   // freopen(".out", "w", stdout);


    char A[]  = {"BKMGTPEZY"};

    int T;
    cin >> T;
    cout.precision(2);
    cout << fixed;
    int it = 0;
    while(T--) {
        ++it;
        int c;
        char ss[5];
        scanf("%d[%s]", &c, ss);

        LD ans;
        if (strcmp(ss, "B") == 0) {
            ans = 0;
        } else {
            LD p = LD(1000) / 1024;
            ans = 1;
            for (int i = 0; A[i] != ss[0]; ++i) {
                ans *= p;
            }
            ans = (1 - ans) * 100;
        }
        cout << "Case #" << it << ": " << ans << "%\n";
    }

    return 0;
}
