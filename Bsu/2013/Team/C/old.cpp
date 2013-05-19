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

#define MAXL 666666

int MN[MAXL * 3];
char ss[MAXL], s[MAXL];
int n, m, cnt[MAXL], id[20][MAXL], suf[MAXL], nsuf[MAXL], lcp[20][MAXL], LG[MAXL], num[MAXL], ll[MAXL];
pair<int, int> p[MAXL];

inline int LCP(int i, int j) {
	if (i == j) return n - suf[i] + 1;
	if (i < j) {
		int t = LG[j - i];
		return min(lcp[t][i + 1], lcp[t][j - (1 << t) + 1]);
	} else {
		int t = LG[i - j];
		return min(lcp[t][j + 1], lcp[t][i - (1 << t) + 1]);
	}
}

int up[MAXL][60];
int down[MAXL][60];

LL msks[MAXL * 60 + 10];
int ccnt;

#define min2(a, b) (b ^ ((a ^ b) & -(a < b)))
#define max2(a, b) (a ^ ((a ^ b) & -(a < b)))

int main() {
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);

	scanf("%d\n", &m);
	for (int i = 0; i < m; ++i) {
		gets(s);
		int l = strlen(s);

		for (int j = 0; j < l; ++j) {
			num[n] = i;
			ll[n] = l - j;
			ss[n++] = s[j] - 'a' + 1;
		}
		num[n] = -1;
		ss[n++] = 0;
	}

	for (int i = 0; i < n; ++i) MN[i] = MN[i + n] = MN[i + n + n] = i;

	LG[1] = 0;
	for (int i = 2; i <= n; ++i) LG[i] = LG[i >> 1] + 1;

	cerr << "read: " << clock() << endl;



	for (int i = 0; i < n; ++i) ++cnt[ss[i]];
	for (int i = 1; i < 30; ++i) cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i) {
		suf[ --cnt[ss[i]] ] = i;
		id[0][i] = ss[i];
	}


	int h;
	for (h = 0; (1 << h) <= n; ++h) {

	#ifdef DEBUG
		for (int i = 0; i < n; ++i) {
			for (int j = suf[i]; j < n; ++j) {
				putchar(ss[j] + 'a' - 1);
			}
			printf(" %d\n", id[h][suf[i]]);
		}
		puts("");
	#endif
	

		int last = 0, idcnt = -1;
		int* I = id[h], *IN = id[h + 1];

		p[0] = make_pair(I[ suf[0] + MN[0 + (1 << h)] ], suf[0]);
		for (int i = 1; i < n; ++i) {
			if (I[suf[i]] != I[suf[i - 1]]) {
				sort(p + last, p + i);

				int lastid = -1;
				for (int j = last; j < i; ++j) {
					if (p[j].first != lastid) ++idcnt;
					lastid = p[j].first;

					nsuf[j] = p[j].second;
					IN[p[j].second] = idcnt;
				}
				last = i;
			}
			p[i] = make_pair(I[ MN[suf[i] + (1 << h)] ], suf[i]);
		}
		sort(p + last, p + n);
		int lastid = -1;
		for (int j = last; j < n; ++j) {
			if (p[j].first != lastid) ++idcnt;
			lastid = p[j].first;
			nsuf[j] = p[j].second;
			IN[p[j].second] = idcnt;
		}

		memcpy(suf, nsuf, n * sizeof(int));
	}

	#ifdef DEBUG
	for (int i = 0; i < n; ++i) {
		for (int j = suf[i]; j < n; ++j) {
			putchar(ss[j] + 'a' - 1);
		}
		printf(" %d\n", id[h][suf[i]]);
	}
    #endif

	cerr << "sufmass: " << clock() << endl;

    for (int i = 1; i < n; ++i) {
    	int x = suf[i - 1];
    	int y = suf[i];
    	for (int j = h; j >= 0; --j) {
    		if (id[j][x] == id[j][y]) {
    			lcp[0][i] += (1 << j);
    			x += (1 << j);
    			y += (1 << j);
    		}
    	}
    }

    for (int j = 0; (1 << j) <= n; ++j)
	    for (int i = 1; i + (1 << j) < n; ++i)
	    	lcp[j + 1][i] = min(lcp[j][i], lcp[j][i + (1 << j)]);


	#ifdef DEBUG
	puts("");
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = suf[i]; k < n; ++k) {
				putchar(ss[k] + 'a' - 1);
			}
			putchar(' ');
			for (int k = suf[j]; k < n; ++k) {
				putchar(ss[k] + 'a' - 1);
			}
			printf(" %d %d\n", LCP(i, j), LCP(j, i));
		}
	}
	#endif


	cerr << "lcp: " << clock() << endl;

	memset(up, -1, sizeof(up));
	memset(down, 63, sizeof(down));

	for (int i = 0; i < n; ++i) {
		if (i)
			for (int j = 0; j < m; ++j) up[i][j] = up[i - 1][j];	
		if (num[ suf[i] ] != -1) up[ i ][ num[suf[i]] ] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (i < n - 1)
			for (int j = 0; j < m; ++j) down[i][j] = down[i + 1][j];	
		if (num[ suf[i] ] != -1) down[ i ][ num[suf[i]] ] = i;
	}

	cerr << "updown: " << clock() << endl;

	static pair<int, int> a[222];
	static int an;

	for (int i = 0; i < n; ++i) {
		if (num[ suf[i] ] == -1) continue;

		an = 0;
		for (int j = 0; j < m; ++j) {
			int val1 = (up[i][j] >= 0) ? LCP(i, up[i][j] ) : 0;
			int val2 = (down[i][j] < n) ? LCP(i, down[i][j] ) : 0;
			val1 = max(val1, val2);
			int val = min(val1, ll[suf[i]]);
			if (val)
				a[an++] = make_pair(val, j);
		}
		sort(a, a + an, greater< pair<int, int> >());

		LL cur = 0;
        for (int j = 0; j < an; ++j) {
        	 if (j && a[j].first != a[j - 1].first) {
       	 		msks[ccnt++] = cur;	
        	 }
        	 cur |= (1LL << a[j].second);
        }
      	msks[ccnt++] = cur;	
	}

	cerr << "calc masks: " << clock() << endl;
	
	sort(msks, msks + ccnt);
	ccnt =  unique(msks, msks + ccnt) - msks;
	cout << ccnt  << endl;

	#ifdef DEBUG
	for (int i = 0; i < ccnt; ++i) {
		cerr << msks[i] << endl;
	}
	#endif

	cerr << "sort and out: " << clock() << endl;

    return 0;
}
