#include <bits/stdc++.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
using namespace std;

void dfs(int x, vector< vector<int> >& g, vector<int>& v) {
	set<int> w;
	for (int i = 0; i < (int)g[x].size(); ++i) {	
		dfs(g[x][i], g, v);
		w.insert(v[g[x][i]]);
	}
	v[x] = 1;
	while (w.count(v[x])) ++v[x];
}

void F(int x, vector< vector<int> >& g, vector< vector<int> >& f) {
	for (int i = 0; i < (int)g[x].size(); ++i) {
		F(g[x][i], g, f);
	}
	for (int val = 1; val <= 20; ++val) {
		int& total = f[x][val] = val;
		for (int i = 0; i < (int)g[x].size(); ++i) {
			int mi = 1e9;
			for (int j = 1; j <= 20; ++j) 
				if (j != val && f[g[x][i]][j] < mi)
					mi = f[g[x][i]][j];
		    total += mi;
		}
	}
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
	vector< vector<int> > g;
	vector< vector<int> > f;
	for (int __case = 1; __case <= T; ++__case) {
		int n;
		
		cin >> n;
		g.assign(n + 1, vector<int>());
		f.assign(n + 1, vector<int>(21));
		for (int i = 1; i <= n; ++i) {
			int x;
			cin >> x;
			g[x].push_back(i);
		}
		//dfs(1, g, v);
		//int pseudoans = accumulate(v.begin(), v.end(), 0);

		F(1, g, f);
		int ans = *min_element(f[1].begin() + 1, f[1].end());
		cout << "Case #" << __case << ": " << ans << endl;
		//cerr << __case << endl;
		//cerr << ans << " " << pseudoans << endl;
		//assert(ans <= pseudoans);
	}

    return 0;
}
