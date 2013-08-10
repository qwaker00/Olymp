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

#define MAXLEN 111111

struct state {
    int len, link;
    map<int, int> next;
};

int a[MAXLEN];
state st[MAXLEN * 3];
ULL d[MAXLEN * 3];
int was[MAXLEN * 3];
int sz, last;

void sa_init() {
    for (int i = 0; i <= sz; ++i) st[i].next.clear();

    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}

void sa_extend (int c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c] = cur;
    if (p == -1)
        st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len)
            st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int T;

void dfs(int x) {
    was[x] = T + 1;
    d[x] = 1;
    for (map<int, int>::iterator j = st[x].next.begin(); j != st[x].next.end(); ++j) {
        if (was[j->second] != T + 1) dfs(j->second);
        d[x] += d[j->second];
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);

        sa_init();

        scanf("%d", &a[0]);
        for (int i = 1; i < n; ++i) {
            scanf("%d", &a[i]);
            sa_extend(a[i] - a[i - 1] + 100);
        }
  /*
        set<vector<int> > all;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> c;
                for (int k = i; k < j; ++k) c.push_back(a[k + 1] - a[k]);
                all.insert(c);
            }
        }
        cerr << all.size() << endl;


        for (int i = 0; i < sz; ++i) {
            cerr << i << ": ";
            for (map<int, int>::iterator j = st[i].next.begin(); j != st[i].next.end(); ++j) {
                cerr << j->first - 100 << " " << j->second << ", ";
            }         
            cerr << endl;
        }
*/
        dfs(0);
        cout << (d[0] - 1) % 1000000009 << endl;
    }
    
    return 0;
}
