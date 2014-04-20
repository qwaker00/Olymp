#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef unsigned long long ULL;
typedef long double LD;
using namespace std;

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    cin >> T;
    for (int __it = 1; __it <= T; ++__it) {
        ULL n;
        char s[111];
        char ans[111];

        cin >> s >> n;
        int l = strlen(s);
        sort(s, s + l);

        int len = 0;
        ULL c = 1;
        do {
            ++len;
            if (n <= LD(l) * c || n <= l * c) break;
            c *= l;
            n -= c;
        } while (true);

        --n;
        ans[len] = 0;
        for (int i = 0; i < len; ++i) {
            ans[len - i - 1] = s[n % l];
            n /= l;
        }

        printf("Case #%d: %s\n", __it, ans);
    }   
    
    return 0;
}
