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

struct Block {
    int v;
    int t, f;
    int end;

    bool operator<(const Block& t)const {
        return v < t.v;
    }
} B[N], lastb;
int bn, bid[N];
vector<int> BB[N];

pair<char, int> a[N];
char ans[N];
int n;

int main() {
    freopen("truth.in", "r", stdin);
    freopen("truth.out", "w", stdout);
    
    scanf("%d\n", &n);

    int lastbucks = -1;
    for (int i = 0; i < n; ++i) {
        a[i].first = getchar();
        if (a[i].first == '$') {
            scanf("%d\n", &a[i].second);
            lastbucks = i;
        } else {
            scanf("\n");
        }
    }

    if (lastbucks == -1) {
        int last = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = last ? 't' : 'f';
            last = (last && a[i].first == '+') || (!last && a[i].first == '-');
        }
        if (last == 1) {
            ans[n] = 0;
            puts("consistent");
            puts(ans);
            return 0;
        }

        last = 0;
        for (int i = 0; i < n; ++i) {
            ans[i] = last ? 't' : 'f';
            last = (last && a[i].first == '+') || (!last && a[i].first == '-');
        }
        if (last == 0) {
            ans[n] = 0;
            puts("consistent");
            puts(ans);
            return 0;
        }
        puts("inconsistent");

        return 0;    
    }
    rotate(a, a + (lastbucks + 1) % n, a + n);

    for (int i = 0; i < n; ++i) {
        if (a[i].first == '$') {
            Block b;

            b.v = a[i].second;
            b.t = 1;
            b.f = 0;

            bid[i] = bn;
            int j = i - 1, last = 1;
            while (j >= 0 && a[j].first != '$') {
                bid[j] = bn;
                if ( (last == 1 && a[j].first == '+') || (last == 0 && a[j].first == '-') ) {
                    ++b.t;
                    last = 1;
                } else {
                    last = 0;
                }
                --j;
            }
            j = i - 1, last = 0;
            while (j >= 0 && a[j].first != '$') {
                if ( (last == 1 && a[j].first == '+') || (last == 0 && a[j].first == '-') ) {
                    ++b.f;
                    last = 1;
                } else {
                    last = 0;
                }
                --j;
            }
            b.end = i;

            BB[b.v].push_back(bn);
            B[bn++] = b;
        }
    }

    int ctrue = 0;
    for (int i = 0; i < bn; ++i) ctrue += B[i].f;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < (int)BB[i].size(); ++j) {
            ctrue -= B[ BB[i][j] ].f;
            ctrue += B[ BB[i][j] ].t;
        }        

        if (ctrue == i) {
            puts("consistent");
            int last = 0;
            for (int j = 0; j < bn; ++j) {
                ans[ B[j].end ] = (B[j].v == i) ? 't' : 'f';
                for (int k = B[j].end - 1; k >= last; --k) {
                    if ( (ans[k + 1] == 't' && a[k].first == '+') || (ans[k + 1] == 'f' && a[k].first == '-') )
                        ans[k] = 't';
                    else
                        ans[k] = 'f';
                }
                last = B[j].end + 1; 
            }
            ans[n] = 0;
            rotate(ans, ans + (n + n - lastbucks - 1) % n, ans + n);
            puts(ans);
            return 0;
        }

        for (int j = 0; j < (int)BB[i].size(); ++j) {
            ctrue -= B[ BB[i][j] ].t;
            ctrue += B[ BB[i][j] ].f;
        }        
    }
    puts("inconsistent");


    return 0;
}
