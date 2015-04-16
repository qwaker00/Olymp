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
#include <thread>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;
string s[111];
vector<int> g[33];
int was[33];
char ans[33];
int an = 0;

void ERR() {
	cout << "Impossible\n";
	exit(0);
}

void dfs(int x) {
	if (was[x]) { 
		if (was[x] == 2)
			ERR();
		return;
	}
	was[x] = 2;
	for (int i = 0; i < g[x].size(); ++i)
		dfs(g[x][i]);
	was[x] = 1;
	ans[an++] = x + 'a';
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
    cin >> n;
    for (int i =0; i < n;++i) {
    	cin >> s[i];
    }
    for (int i = 1; i < n; ++i) {
    	int j = 0;
    	while (j < s[i - 1].length() && j < s[i].length() && s[i - 1][j] == s[i][j]) ++j;
    	if (j == s[i - 1].length()) continue;
    	if (j == s[i].length()) {
	    	ERR();
    	}
    	g[s[i][j] - 'a'].push_back(s[i - 1][j] - 'a');
//    	cerr << s[i - 1][j] << " " << s[i][j] << endl;
    }

    for (int i = 0; i < 26; ++i)
    	if (!was[i]) {
    		dfs(i);
    	}

	cout << ans << endl;
	
    return 0;
}
