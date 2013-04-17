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

int n, m, a[111111], b[111111], nb[111111];

#define TH 333
#define MAX 1111

struct Tp {
    int l, r, next;
    char t;
} T[MAX + 1];


vector<int> freeS;

inline int New() {
    int x = freeS.back();
    freeS.pop_back();
    return x;
}

inline void Free(int i) {
    freeS.push_back(i);
}

inline void Init() {
    freeS.clear();
    for (int i = MAX - 1; i >= 0; --i) freeS.push_back(i);
    T[MAX].next = 0;
    int id = New();
    T[id].next = -1;
    T[id].t = 'b';
    T[id].l = 0;
    T[id].r = n - 1;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    Init();

    while (m--) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);

            int ld = y - 1;
            int rd = ld + k - 1;

            bool first = true;
            int cnt = 0;

            for (int i = T[MAX].next, prev = MAX; i != -1; prev = i, i = T[prev].next) {                
                int ll = cnt, rr = cnt + T[i].r - T[i].l;
                cnt += T[i].r - T[i].l + 1;

                if (rr < ld || ll > rd) continue;
                if (ld < ll && rr < rd) {
                    T[prev].next = T[i].next;
                    Free(i);
                    i = prev;
                } else {
                    T[prev].next = T[i].next;

                    if (ll < ld) {
                        int id = New();
                        T[id] = T[i];
                        T[id].r = T[i].l + ld - ll - 1;
                        T[id].next = T[i].next;
                        T[prev].next = id;
                        prev = id;
                    }

                    if (first) {
                        int id = New();
                        T[id].t = 'a';
                        T[id].l = x - 1;
                        T[id].r = T[id].l + k - 1;
                        T[id].next = T[prev].next;
                        T[prev].next = id;
                        prev = id;
                        first = false;
                    }

                    if (rr > rd) {
                        int id = New();
                        T[id] = T[i];
                        T[id].l = T[i].r - (rr - rd) + 1;
                        T[id].next = T[prev].next;
                        T[prev].next = id;
                        prev = id;
                    }
                    Free(i);
                    i = prev;
                }
            }
            //cerr << cnt << endl;
            //cerr << MAX - freeS.size() << endl;
            if (MAX - freeS.size() > TH) {
                int nbc = 0;

                for (int i = T[MAX].next; i != -1; i = T[i].next) {
                    if (T[i].t == 'a')
                        for (int j = T[i].l; j <= T[i].r; ++j)
                            nb[nbc++] = a[j];
                    else        
                        for (int j = T[i].l; j <= T[i].r; ++j)
                            nb[nbc++] = b[j];                       
                }
                for (int i = 0; i < n; ++i) b[i] = nb[i];
                Init();
              //  cerr << "qwe" << endl;
            }
        } else
        if (t == 2) {
            int x;
            scanf("%d", &x);
            --x;
            for (int i = T[MAX].next, cnt = 0; i != -1; i = T[i].next) {
                cnt += T[i].r - T[i].l + 1;
                
                if (cnt > x) {
                    if (T[i].t == 'a') {
                        printf("%d\n", a[T[i].r - (cnt - x - 1)]);
                    } else {
                        printf("%d\n", b[T[i].r - (cnt - x - 1)]);
                    }
                    break;
                }
            }
        }
    }
    
    return 0;
}
