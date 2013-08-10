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


void NO() {
    puts("NO");
    exit(0);
}

int n;
vector<LL> a, b;

int main() {
    freopen("stones.in", "r", stdin);
    freopen("stones.out", "w", stdout);

    scanf("%d", &n);
    a.resize(n);
    for (int i= 0; i < n; ++i) {
        scanf("%I64lld", &a[i]);
    }

    while (n > 1) {
        if (n & (n - 1)) NO();

        sort(a.begin(), a.end());

        LL val = a[0];
        int cnt = 1, mx = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                ++cnt;
                if (cnt > mx) {
                    mx = cnt;
                    val = a[i];
                }
            } else {
                cnt = 1;
            }
        }
        cnt = mx;
        if (cnt < n / 2) NO();
        cnt = n / 2;
        b.resize(cnt);
        for (int i = 0, bn = 0; i < n; ++i)
            if (a[i] == val && cnt) {
                --cnt;
            }else b[bn++] = a[i];
        a.swap(b);
        n = a.size();        
    }

    cout << "YES" << endl;
    
    return 0;
}
