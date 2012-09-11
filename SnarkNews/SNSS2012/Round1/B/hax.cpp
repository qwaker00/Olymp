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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 2222

int l, la;
char s[N];
int p[N];
int f[2][N][N], g[N][N];

void Add(int& a, int b) {
	a = (a + b) % 10000;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> l >> la >> (s + 1);

    p[1] = 0;
    for (int i = 2; i <= la; i++) {
    	int k = p[i - 1];
    	while (k > 0 && s[k + 1] != s[i]) k = p[k];
    	if (s[k + 1] == s[i]) p[i] = k + 1;else p[i] = 0;
    }

    int ans = 0;
    f[0][0][0] = 1;
    for (int it = 0; it < 2; it++)
    for (int i = 0; i < l; i++) {    	
    	for (int j = 0; j <= la; j++) if (f[it][i][j]) {
    		for (int t = 0; t < 2; t++) {
    			if (s[j + 1] == t + 48)
	    			g[j][t] = j + 1;else
	    			g[j][t] = g[p[j]][t];
				Add(f[it | (g[j][t] == la)][i + 1][g[j][t]], f[it][i][j]);
    		}
    	}
    }
    for (int i = 0; i <= la; i++) Add(ans, f[1][l][i]);
    cout << ans << endl;

    return 0;
}
