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
#include <unordered_map>
#include <tuple>
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


typedef ULL TParty;

int Hash[12][1100111];
int n, m;
int a[1100111];
TParty p[2200111];

unordered_map< TParty, int > cnt;


ULL Hashv(int* a, int n, int off) {
    unsigned h1 = 0;
    unsigned h2 = 0;
    unsigned h3 = 0;
    for (int i = 0; i < n; ++i) {
        h1 ^= Hash[off][a[i]];
        h2 ^= Hash[off + 1][a[i]];
        h3 ^= Hash[off + 2][a[i]];
    }
    return (ULL(h1) << 10) ^ (ULL(h2) << 5) ^ h3;
}

int main() {
    freopen("party.in", "r", stdin);
    freopen("party.out", "w", stdout);


    for (int j = 0; j < 9; ++j) {
        for (int i = 0; i < 1048576; ++i) Hash[j][i] = i;
        random_shuffle(Hash[j], Hash[j] + 1048576);
    }

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[j]);
            --a[j];
        }
        p[i] = (Hashv(a, k, 0) << 15) ^ (Hashv(a, k, 3) << 30) ^ Hashv(a, k, 6);
        ++cnt[p[i]];
    }
    int nn = n;
    for (int i = 0; i < m; ++i) {
        int p1, p2;
        scanf("%d%d", &p1, &p2);
        p[nn++] = p[p1 - 1] ^ p[p2 - 1];
        int& c = cnt[ p[nn - 1] ];
        printf("%d ", c);
        ++c;
    }
//    cerr << clock() << endl;

    return 0;
}
