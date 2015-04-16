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

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const double PI = 3.1415926535897932384626433832795;
template<typename T>
T sqr(T x) { return x * x; }

using namespace std;

char s[55][55];
int n;


inline int id(char x) {
	if (x >= 'a') return x - 'a' + 26;
	return x - 'A';
}

inline char deid(int x) {
	if (x >= 26) return x - 26 + 'a';
	return x + 'A';
}

struct TCost {
	char cnt[52];

	void operator+=(char x) {
		if (x == 0) return;
		if (x > 0) 
			++cnt[id(x)];
		else
			--cnt[id(-x)];
	}

	bool operator<(const TCost& t) const {
		for (int j = 0; j < 52; ++j)
			if (cnt[j] != t.cnt[j])
				return cnt[j] < t.cnt[j];
		return false;
	}

	void out() {
		for (int i = 0; i < 52; ++i) 
			for (int j = 0; j < cnt[i]; ++j)
				putchar(deid(i));
		puts("");
	}
} D[111];
int st[111], P[111];
int f[111][111], c[111][111];
vector<int> g[111];

void add(int x, int y, int cost) {
	g[x].push_back(y);
	f[x][y] = 1;
	c[x][y] = -cost;

	g[y].push_back(x);
	f[y][x] = 0;
	c[y][x] = cost;
//	cerr << x << " " << y << " " << cost << endl;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
    	gets(s[i]);
    }

    const int S = 0;
    const int T = n + n + 1;
    for (int i = 0; i < n; ++i) {
    	add(S, i + 1, 0);
    	add(i + 1 + n, T, 0);  
    	for (int j = 0; j < n; ++j) {
    		add(i + 1, j + 1 + n, s[i][j]);
    	}
    }

    TCost ans;
    memset(ans.cnt, 0, sizeof(ans.cnt));
	for (int it = 0; it < n; ++it) {
		memset(D, 127, sizeof(D));
		memset(st, 0, sizeof(st));
		memset(D[S].cnt, 0, sizeof(D[S].cnt));
		deque<int> q;
		q.push_back(S);
		st[S] = 1;
		while (!q.empty()) {
			int x = q.front(); q.pop_front();
			st[x] = 2;
		    for (int j = 0; j < g[x].size(); ++j) {
		    	int y = g[x][j];
		    	if (f[x][y] <= 0) continue;
		    	D[x] += c[x][y];
		    	if (D[x] < D[y]) {
			    	D[y] = D[x];
			    	P[y] = x;
			    	if (st[y] == 0)
			    		q.push_back(y);
			    	else
			    	if (st[y] == 2)
			    		q.push_front(y);
			    	st[y] = 1;
			    }
		    	D[x] += -c[x][y];
		    }
		}
		int x = T;
		while (x != S) {
			ans += -c[ P[x] ][x];
			--f[P[x]][x];
			++f[x][P[x]];
			x = P[x];
		}
	}
	ans.out();

    return 0;
}
