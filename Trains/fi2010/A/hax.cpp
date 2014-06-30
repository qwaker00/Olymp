#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef unsigned long long ULL;

int d[111][111];

int main() {
//    freopen(".in", "r", stdin);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 4; ++j) if (s[j * 2] != '0')
            for (int k = 0; k < 4; ++k) if (k != j && s[k * 2] != '0') {
                d[ (s[j*2]-'A')*2 + (s[j*2+1] == '+') ] [ (s[k*2]-'A')*2 + (s[k*2+1] == '-') ] = 1;
            }
    }
    int N = (('Z' - 'A')*2 + 1);
    for (int k = 0; k <= N; ++k)
        for (int i = 0; i <= N; ++i)
            for (int j = 0; j <= N; ++j)
                if (d[i][k] && d[k][j])
                    d[i][j] = 1;
    for (int i = 0; i <= N; ++i) if (d[i][i]) {
        puts("unbounded");
        return 0;
    }
    puts("bounded");
    return 0;
}
