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

#define N 1111111

pair<int, int> p[N];
int b1[N], b2[N], b3[N], b4[N], *id = b3, *nid = b4, *suf = b1, *nsuf = b2, modl[N+N+N], cnt[N], lcp[N];
char s[N];
int l;

int main() {
    freopen("decimal.in", "r", stdin);
    freopen("decimal.out", "w", stdout);
    
    char c1 = getchar();
    char c2 = getchar();
    gets(s);
    l = strlen(s);
    s[l++] = '0' - 1;
    

    time_t st = clock();

    for (int i = 0; i < l + l + l; ++i) modl[i] = i % l;
    for (int i = 0; i < l; ++i) {
        s[i] -= '0' - 1;
        ++cnt[s[i]];
    }
    for (int i = 1; i <= 10; ++i) cnt[i] += cnt[i - 1];
    for (int i = l - 1; i >= 0; --i) {
        int p = --cnt[s[i]];
        suf[ p ] = i;
        id[i] = s[i];
    }
    int maxid = 10;

    for (int h = 0; (1 << h) < l; ++h) {
        int hh = (1 << h);
        /*
        for (int i = 0; i < l; ++i) {
            for (int j = suf[i]; j <l; ++j) putchar(s[j] + '0' - 1);
            puts("");
        }
        puts("");
        */


        memset(cnt, 0, (maxid + 1) * sizeof(int));
        for (int i = 0; i < l; ++i) ++cnt[id[i]];
        for (int i = 1; i <= maxid; ++i) cnt[i] += cnt[i - 1];

        for (int i = l - 1, j; i >= 0; --i) {
            j = modl[suf[i] - hh + l];
            nsuf[ --cnt[ id[j] ] ] = j;
        }

        int cid = 0;
        for (int i = 0; i < l; ++i) {
            if (i > 0 && (id[nsuf[i]] != id[nsuf[i - 1]] || id[modl[nsuf[i] + hh]] != id[modl[nsuf[i - 1] + hh]]) ) ++cid;
            nid[ nsuf[i] ] = cid;
        }
        maxid = cid;

        swap(nsuf, suf);
        swap(nid, id);
    }
    cerr << clock() - st << endl;

    int ansi = 0;
    int ansj = l - 1;
    int last = 0;
    for (int i = 0; i + 1 < l; ++i) {
        int x = i;
        int y = suf[id[i] - 1];
        if (last > 0) --last;
        while (x + last < l && y + last < l && s[x + last] == s[y + last]) ++last;
        lcp[id[x]] = last;
    }
    for (int i = 1; i < l; ++i) {
        int j = suf[i];
        if (lcp[i] >= l - j - 1 && ansj > j) {
            ansj = j;
            ansi = suf[i - 1];
        }
        if (i + 1 < l && lcp[i + 1] >= l - j - 1 && ansj > j) {
            ansj = j;
            ansi = suf[i + 1];
        }
    }
    for (int i = 0; i < l; ++i) s[i] += '0' - 1;


    char ch = 0;
    swap(s[ansi], ch);
    printf("%c%c%s(", c1, c2, s);
    swap(s[ansi], ch);
    swap(s[ansj], ch);
    printf("%s)\n", s + ansi);
    
    return 0;
}
