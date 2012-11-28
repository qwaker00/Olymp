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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 222222

int pr[N], alive[N], dna[N], n, m, k;
char sex[N];

int main() {
    freopen("eve.in", "r", stdin);
    freopen("eve.out", "w", stdout);

    memset(pr, -1, sizeof(pr));
    memset(dna, -1, sizeof(dna));
    memset(alive, 0, sizeof(alive));

    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%c\n", &sex[i]); 
        ++alive[i];
        pr[i] = i;
    }

    scanf("%d\n", &m);
    int idd = n;
    for (int i = 1; i <= m; i++) {
        int x, y;
        char ch;

        scanf("%d", &y);
        if (y < 0) {
            --alive[ pr[-y] ];
            scanf("\n");
        } else {
            int newid = ++idd;
            scanf("%d %c\n", &x, &ch);
            sex[newid] = ch;
            pr[newid] = pr[x];
//            cerr << "connect " << i + n << " " << x << endl;

            ++alive[pr[x]];
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int id, d;
        scanf("%d%d", &id, &d);
        dna[pr[id]] = d;
    }


    bool alleq = true;
    int undef = 0;
    int grcount = 0;
    int onedna = -1;

    for (int i = 1; i <= n + m; i++) if (pr[i] == i && alive[i]) {
//        cerr << i << endl;
        grcount++;
        if (dna[i] == -1) {
            undef++;
        } else if (onedna == -1) {
            onedna = dna[i];
        } else {
            if (onedna != dna[i]) alleq = false;
        }
    }

    if (alleq && (undef == 0 || grcount <= 1)) {
        puts("YES");
    } else
    if (!alleq) {
        puts("NO");
    } else
        puts("POSSIBLY");

    return 0;
}
