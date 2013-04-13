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

#define L 666666
#define N 111111

char pat[L];
char s[L];
int n, p[N], st[N], stn, pf[L], lr, ans = 0;
vector<int> g[N];

void dfs(int x, int cpf) {
	for (int i = st[x]; s[i]; ++i) {
		while (cpf > 0 && pat[cpf] != s[i]) cpf = pf[cpf - 1];
		if (pat[cpf] == s[i]) ++cpf;else cpf = 0;
		if (cpf == lr) {
			++ans;
		}
	}
	for (size_t i = 0; i < g[x].size(); ++i) {	
		dfs(g[x][i], cpf);
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d", &n);
    stn = 1;
    st[1] = 0;
    for (int i = 2; i <= n; ++i) {
    	scanf("%d %s\n", &p[i], s + stn);
    	st[i] = stn;
    	stn += strlen(s + stn) + 1;
    	g[p[i]].push_back(i);
    }

    gets(pat);
    lr = strlen(pat);
    pf[0] = 0;
    for (int i = 1; i < lr; ++i) {
    	int& k = pf[i] = pf[i - 1];
    	while (k > 0 && pat[k] != pat[i]) k = pf[k - 1];
    	if (pat[k] == pat[i]) ++k;else k = 0;
    }
    
    dfs(1, 0);
    cout << ans << endl;

    return 0;
}
