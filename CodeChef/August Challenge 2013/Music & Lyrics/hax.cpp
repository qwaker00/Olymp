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

int n, m;
char w[505][5005], buf[50005];

const int MAXLEN = 1250500;

struct state {
	int len, link;
	int next[64];
};
state st[MAXLEN * 2];
int cnt[MAXLEN * 2];
int sz, last;
vector<int> sorter[MAXLEN];
                     
void sa_init() {
    memset(st, -1, sizeof(st));
	sz = last = 0;
	st[0].len = 0;
	st[0].link = -1;
	++sz;
    sorter[0].push_back(0);
}

void sa_extend (int c) {
	int cur = sz++;
	st[cur].len = st[last].len + 1;
    sorter[ st[cur].len ].push_back(cur);
    cnt[cur] = 1;
	int p;
	for (p = last; p!=-1 && st[p].next[c]==-1; p=st[p].link) st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
            sorter[st[clone].len].push_back(clone);
			memcpy(st[clone].next, st[q].next, sizeof(st[0].next));
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}
int CODE[255];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    cerr << clock() << endl;
    cerr << sizeof(st) << endl;

    for (int i = 'a'; i <= 'z'; ++i) CODE[i] = i - 'a';
    for (int i = 'A'; i <= 'Z'; ++i) CODE[i] = i - 'A' + CODE['z'] + 1;
    for (int i = '0'; i <= '9'; ++i) CODE[i] = i - '0' + CODE['Z'] + 1;
    CODE['-'] = CODE['9'] + 1;
    CODE['$'] = CODE['-'] + 1;
    cerr << CODE['$'] << endl;

    sa_init();
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {        
        gets(w[i]);
    }
    scanf("%d\n", &m);
    int suml = 0;
    for (int i = 0; i < m; ++i) {
        gets(buf);
        for (int j = 0; buf[j]; ++j) {
            sa_extend(CODE[buf[j]]);
            ++suml;
        }
        sa_extend(CODE['$']);
        ++suml;
    }
    cerr << clock() << endl;
    for (int i = suml; i >= 0; --i)
        for (size_t j = 0; j < sorter[i].size(); ++j) {
            cnt[st[ sorter[i][j] ].link] += cnt[sorter[i][j]];
         }
    cerr << clock() << endl;
    for (int i = 0; i < n; ++i) {
        int t = 0;
        for (int j = 0; w[i][j]; ++j) {
            int x = CODE[w[i][j]];
            if (st[t].next[x] != -1) {
                t = st[t].next[x];
            } else {
                t = -1;
                break;
            }
        }
        if (t == -1)
            puts("0");else
            printf("%d\n", cnt[t]);
    }
    cerr << clock() << endl;
     
    return 0;
}
