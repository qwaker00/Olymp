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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int was[33];
bool fob[33][33];
int st[33], sn = 0, cn = 0;
int cycle[33];
int ts[33], tn = 0, f[33], fp[33];

void dfs(int x) {
	if (was[x]) {
		if (!cn) {
			bool start = false;
			for (int j = 0; j < sn; ++j) {
				if (st[j] == x)	start = 1;	
				if (start) cycle[cn++] = st[j];
			}
		}
		return;
	}
	was[x] = 1;
	st[sn++] = x;
	for (int i = 0; i < 26; ++i) 
		if (!fob[x][i]) {
			dfs(i);
			if (cn) return;
		}
	ts[tn++] = x;
	--sn;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
	scanf("%d", &T);
	while (T--) {
		memset(fob, 0, sizeof(fob));
		memset(was, 0, sizeof(was));

		int n;
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			char c1, c2;
			scanf("%c%c\n", &c1, &c2);
			fob[c1 - 'a'][c2 - 'a'] = 1;
		}

		sn = 0;
		cn = 0;
		tn = 0;
		for (int i = 0; i < 26; ++i) if (!was[i]) {
			dfs(i);
			if (cn) break;
		}

		int l;
		if (cn) {
			l = 20;
		} else {
			memset(f, 127 + 63, sizeof(f));			
			int ans = -1e9, ansc = 0;
			for (int i = 0; i < tn; ++i) {
				int x = ts[i];

				f[x] = 1;
				fp[x] = -1;
				for (int j = 0; j < 26; ++j) if (!fob[x][j]) {
					if (f[j] + 1 > f[x]) {
						f[x] = f[j] + 1;
						fp[x] = j;
					}
				}
				if (f[x] > ans) {
					ans = f[x];
					ansc = x;
				}
			}
			while (ansc != -1) {
				cycle[cn++] = ansc;
//				cerr << char(ansc + 'a');
				ansc = fp[ansc];
			}
			l = (cn + 1) / 2;
		}

		for (int i = 0; i < l; ++i) {
			for (int j = 0; j < l; ++j) {
				putchar(cycle[(i + j) % cn] + 'a');
			}
			putchar('\n');
		}
	}

    return 0;
}
