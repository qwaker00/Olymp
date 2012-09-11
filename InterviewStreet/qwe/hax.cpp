#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define MOD 1000000007
#define BN 11111
#define MLEN 11

int n, m;
char s[111][111];
int next[BN][11], dep[BN], vn = 1, root = 0;
vector<int> q[BN];
int suf[BN], last[BN], p[BN], len[BN], go[BN][11];
LL f[111][BN][12];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	cerr << sizeof(f) << endl;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	    int v = root;
	    for (int j = 0; s[i][j]; j++) {
			int ch = s[i][j] - 'a';
			if (!next[v][ch]) last[vn] = ch, p[vn] = v, dep[vn] = j + 1, next[v][ch] = vn++;
			v = next[v][ch];
		}
		len[v] = dep[v];
	}
	for (int i = 0; i < vn; ++i) q[dep[i]].push_back(i);

	for (int i = 0; i < BN; i++)
		for (int j = 0; j < q[i].size(); j++) {
			int v = q[i][j];
			if (v == root || p[v] == root)
				suf[v] = root;
			else
				suf[v] = go[suf[p[v]]][last[v]];
			for (int t = 0; t < 10; t++)
				if (next[v][t])
					go[v][t] = next[v][t];
				else
				go[v][t] = go[suf[v]][t];
			len[v] = max(len[v], len[suf[v]]);
		}

	LL res = 0;
	f[0][0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < vn; j++)
			for (int l = 0; l < MLEN; l++) {
				int F = f[i][j][l];
				if (F > 0) {
					if (i == n) {
						if (l == 0)
              				res = (res + F) % MOD;
          			} else {
						for (int t = 0; t < 10; ++t) {
    			          int v = go[j][t];
			              if (dep[v] < l + 1) continue;
			              int len1 = l + 1;
            			  if (len[v] >= len1) len1 = 0;
            			  f[i + 1][v][len1] = (f[i + 1][v][len1] + F) % MOD;
						}
					}
        		}
			}
	cout << res << endl;
	return 0;
}
