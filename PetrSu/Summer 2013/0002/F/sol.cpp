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

const int N = 6;
const int MOD = 1000000007;

vector< vector<int> > dels;

vector<int> cur; 

void gen(int l, int sum) {
	if (l == N) {
		dels.push_back(cur);
		return;
	}

	if (sum == 0 || l + 1 == N) {
		cur.push_back(sum);
		gen(l + 1, 0);
		cur.pop_back();
		return;
	}

	for (int i = 0; i <= sum; ++i) {
		cur.push_back(i);
		gen(l + 1, sum - i);
		cur.pop_back();
	}
}

int num[255];

vector< pair<int, int> > g[55];

char w[222];
bool used[11];

const int M = 25 * 6 * 2 + 50 + 12 + 10;
int fir[M], tov[M], nxt[M], be[M], cost[M];
int ke;

const int K = 111;
int fact[K], invfact[K]; 

void add(int x, int y, int c) {
	nxt[++ke] = fir[x]; fir[x] = ke; tov[ke] = y; cost[ke] = c;
	nxt[++ke] = fir[y]; fir[y] = ke; tov[ke] = x; cost[ke] = 0;
	be[ke] = ke - 1;
	be[ke - 1] = ke;
}

int S = 49, T = 50;

int from[64], edge[64];
bool dfs(int x) {
	if (x == T) return true;

	for (int t = fir[x]; t; t = nxt[t])
		if (from[ tov[t] ] == -1 && cost[t]) {
			from[ tov[t] ] = x;
			edge[ tov[t] ] = t;
			if (dfs(tov[t])) return true;
		}

	return false;
}

ll inv(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = (res * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return res;
} 

int main() {
	freopen("patterns.in", "r", stdin);
	freopen("patterns.out", "w", stdout);	
	
	fact[0] = 1;
	for (int i = 1; i < K; ++i) {
		fact[i] = (ll(fact[i - 1]) * i) % MOD;
	}
	for (int i = 0; i < K; ++i) {
		invfact[i] = inv(fact[i], MOD - 2);
	}


	num['R'] = 0;
	num['G'] = 1;
	num['Y'] = 2;
	num['C'] = 3;
	num['B'] = 4;
	num['M'] = 5;

	int n;
	cin >> n;
	gen(0, n * n);
	/*
	for (int i = 0; i < dels.size(); ++i) {
		for (int j = 0; j < 6; ++j)
			cerr << dels[i][j] << " ";
		cerr << endl; 
	}
    */

	cin.ignore();
	
	int lim = n * n;
	for (int i = 0; i < lim; ++i) {
		memset(used, 0, sizeof(used));

		gets(w);
		for (int j = 0; j < 6; ++j)
			used[ num[ w[j] ] ] = true;

		for (int j = 0; j < 6; ++j) 
			if (used[j]) {
				add(i, lim + j, 1);
			}
		
		add(S, i, 1);
	}

	for (int j = 0; j < 6; ++j) add(lim + j, T, 0);

	int ans = 0;
	for (int c = 0; c < dels.size(); ++c) {
		for (int t = fir[S]; t; t = nxt[t])
			cost[t] = 1;
		for (int i = 0; i < lim; ++i)
			for (int t = fir[i]; t; t = nxt[t])
				if (tov[t] == S) cost[t] = 0;
				else cost[t] = 1;

		for (int i = 0; i < 6; ++i)
			for (int t = fir[lim + i]; t; t = nxt[t])
				if (tov[t] == T) cost[t] = dels[c][i];
				else cost[t] = 0;

		bool cool = true;
		for (int iter = 0; iter < lim; ++iter) {
			memset(from, -1, sizeof(from));
			if (!dfs(S)) {
				cool = false;
				break;
			}

			int x = T;
			while (x != S) {
				cost[ edge[x] ]--;
				cost[ be[ edge[x] ] ]++;
				x = from[x];
			}
		}

		if (cool) {
		    ll add = fact[lim];
		    for (int i = 0; i < 6; ++i) {
		    	add = (add * invfact[ dels[c][i] ]) % MOD;
		    }
		    ans = (ans + add) % MOD;
		}
	}

	cout << ans << endl;

	return 0;
}
