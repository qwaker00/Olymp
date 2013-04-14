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
typedef unsigned long long LL;
//typedef unsigned long long ULL;
//typedef unsigned int LL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int ed[111];
char* s, ss[55555][11];
int n, k, ec[111], mi[55555], mic[55555];
LL h[55555];

//map<LL, int> all;
//map<LL, pair<int, int> > any;

//#define MASK 8388607
//#define MASK 4194303
#define MASK 2097151
//#define MASK 1048575

struct Tp {
    LL hash;
    int cnt;
    int f;
    int s;
};
vector<Tp> H[MASK + 1];

bool ByEd(int x, int y) {
    return ed[x] < ed[y];
}

inline void Modify(LL hash, int ed, int i) {
    vector<Tp>& cur =  H[hash & MASK];
    for (size_t j = 0; j < cur.size(); ++j)
        if (cur[j].hash == hash) {
            ++cur[j].cnt;
            cur[j].s = i + 1;
            return;
        }
    Tp t;
    t.hash = hash;
    t.f = i + 1;
    t.cnt = 1;
    cur.push_back(t);
}

bool GetPair(LL hash, int i, int& res) {
    vector<Tp>& cur =  H[hash & MASK];
    for (size_t j = 0; j < cur.size(); ++j)
        if (cur[j].hash == hash) {
            if (cur[j].cnt <= 1) return false;
            if (cur[j].f == i + 1)
                res = cur[j].s;else
                res = cur[j].f;
            return true;
        }
    return false;
}

int main() {
    freopen("similar.in", "r", stdin);
    freopen("similar.out", "w", stdout);
    
    scanf("%d%d\n", &n, &k);

    ed[0] = 0;
    for (int j = 1; j < (1 << k); ++j) {
        ed[j] = ed[j & (j - 1)] + 1;
        ec[j] = j;
    }
    sort(ec + 1, ec + (1 << k), ByEd);
    for (int i = 0; i < n; ++i) {
        gets(ss[i]);
        mi[i] = 1e9;
    }

    int found = 0;
    for (int _j = 0; _j < (1 << k) && found < n; ++_j) {
        int j = ec[_j];
        
        for (int i = 0; i < n; ++i) {
            s = ss[i];

            LL hash = 0;
            for (int p = 0; p < k; ++p) if (j & (1 << p)) {
                hash = hash * 97 + 95;
            } else {
                hash = hash * 97 + s[p] - 33 + 1;
            }
            h[i] = hash;

            Modify(hash, ed[j], i);
        }
        for (int i = 0; i < n; ++i) {
            if (mi[i] <= ed[j]) continue;

            int pp;
            if (GetPair(h[i], i, pp)) {
                mi[i] = ed[j];
                mic[i] = pp;
                ++found;
            }
        }
        for (int i = 0; i < n; ++i) H[h[i] & MASK].clear();
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", mi[i], mic[i]);
    }
    cerr << clock() << endl;
    
    return 0;
}
