#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 200222;
const int M = 19;

char w[N];
int balance[N];

int suf[N], cnt[N], classes, p[N], mod[N + N + N];
int cls[M][N];

int lcp[N];

vector<int> g[N];
map<int, int> where;
int kv;

pair<int, int> st;
int rmin[N];

int main() {
	freopen("abyss.in", "r", stdin);
	freopen("abyss.out", "w", stdout);	
	
	gets(w);
    int l = strlen(w);

	if (w[0] == '0') balance[0] = 1;
	else balance[0] = -1;

	for (int i = 1; i < l; ++i) {
		int add = w[i] == '0' ? 1 : -1;
		balance[i] = balance[i - 1] + add;
	}

	kv = 0;
	for (int i = 0; i < l; ++i) {
		map<int, int>::iterator it = where.find(balance[i]);
		int pos;
		if (it == where.end()) {
			pos = where[ balance[i] ] = kv++;
		} else pos = it->second;

		g[pos].push_back(i);
	}

    l++; // add 0 to string
    for (int i = 0; i < l; ++i) {
    	mod[i] = mod[i + l] = mod[i + l + l] = i;
    }

    classes = 256;
	for (int i = 0; i < l; ++i) {
		cnt[ w[i] ]++;
		cls[0][i] = w[i];
	}
	for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
	for (int i = l - 1; i >= 0; --i) {
		suf[ --cnt[ w[i] ] ] = i;
	}

	int mm = 0;
	for (int h = 0; (1 << h) <= l; ++h) {
		mm = h + 1;
		int half = 1 << h;
		memset(cnt, 0, sizeof(cnt[0]) * (classes + 3));

		for (int i = 0; i < l; ++i) {
			p[i] = mod[suf[i] + l - half];
			cnt[ cls[h][i] ]++;
		}
		for (int i = 1; i <= classes; ++i) {
			cnt[i] += cnt[i - 1];
		}

		for (int i = l - 1; i >= 0; --i) {
			suf[ --cnt[ cls[h][ p[i] ] ] ] = p[i];
		}

		int classes = 1;
		cls[h + 1][ suf[0] ] = 0;
		for (int i = 1; i < l; ++i) {
			if (cls[h][ suf[i] ] != cls[h][ suf[i - 1] ] || cls[h][ mod[ suf[i] + (1 << h) ] ] != cls[h][ mod[ suf[i - 1] + (1 << h) ] ]) {
				++classes;
			}
			cls[h + 1][ suf[i] ] = classes - 1;
		}
	}


	for (int i = 0; i + 1 < l; ++i) {
		int x = suf[i], y = suf[i + 1];
		for (int j = mm; j >= 0; --j) {
			if (cls[j][x] == cls[j][y]) {
				lcp[i] += (1 << j);
				x = mod[x + (1 << j)];
				y = mod[y + (1 << j)];
			}
		}
	}

    /*
	for (int i = 0; i < l; ++i) {
		printf("%s %d\n", w + suf[i], lcp[i]);
	}
    */

	sz = 1;
	st[0] = make_pair(l, balance[l - 1]);
	for (int i = l - 1; i >= 0; --i) {
		int cur = i == 0 ? 0 : balance[i - 1];

		while (st[sz - 1].second >= balance[i])
	}

    for (int i = 1; i < l; ++i) {
    	int pos = suf[i];

    	int border = pos + lcp[ suf[pos] ];

    }

	return 0;
}
