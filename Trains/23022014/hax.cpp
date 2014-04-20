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

template<int N, int M>
struct Packed {    
    unsigned char data[(M * N + 7) / 8 + 4];

    int get(int i) {
        int bit = i * M;
        unsigned* ptr = ((unsigned*)data) + (bit >> 5);
        if ((bit & 31) + M <= 32)
            return ((*ptr) >> (bit & 31)) & ((1u << M) - 1);
        else
            return (((*ptr) >> (bit & 31)) | ((*(ptr + 1)) << (32 - (bit & 31))) ) & ((1u << M) - 1);
    } 

    void set(int i, unsigned x) {
        int bit = i * M;
        int off = bit & 31;
        unsigned* ptr = ((unsigned*)data) + (bit >> 5);
        if (off + M <= 32) {
            (*ptr) &= ~(((1u << M) - 1) << off);
            (*ptr) |= (x << off);
        } else {
            int off = bit & 31;
            int l = 32 - off;
            int r = M - l;

            (*ptr) &= ~(((1u << l) - 1) << off);
            (*(ptr + 1)) &= ~((1u << r) - 1);

            (*ptr) |= (x & ((1u << l) - 1)) << off;
            (*(ptr + 1)) |= (x >> l);
        }
    } 
};

Packed<1000002, 20> l, r, q;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
//    cerr << sizeof(l) + sizeof(r) + sizeof(q) << endl;

    int n; 
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        l.set(i, x);
        r.set(i, y);
    }
    puts("BFS");

    long long ans = 0;
    int q1 = 0, q2 = 0, q3 = 0, d = 0;
    q.set(q2++, 1); q3 = 1;
    while (q1 < q2) {
        for (int i = q1; i < q2; ++i) {
            int x = q.get(i);
            printf("%d\n", x);
            ans += d;
            int ll = l.get(x);
            int rr = r.get(x);
            if (ll) q.set(q3++, ll);
            if (rr) q.set(q3++, rr);
        }
        d += 1;
        q1 = q2;
        q2 = q3;        
    };

    cout << ans << endl;
    
    return 0;
}
