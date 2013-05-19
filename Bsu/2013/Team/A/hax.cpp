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

const int N = 100011;

char a[N];

struct bor {
	int go[N][26];
	int cnt;

	bor() {
		memset(go, -1, sizeof(go));
		cnt = 1;
	}

	void add() {
		int cur = 0;
        for (int i = 0; a[i]; ++i) {
        	int y = a[i] - 'a';
			if (go[cur][y] == -1) {
				go[cur][y] = cnt++;
			} 
			cur = go[cur][y];
        }
	}
} A, B;

int n, m;
LL ans;

int cnt[444];

void dfs(int x, int c, int h) {
	if (h > 1) {
		cnt[c]++;
	}

	for (int i = 0; i < 26; ++i) {
		if (B.go[x][i] != -1) {
			dfs(B.go[x][i], i, h + 1);
		}
	} 
}


int main() {
    freopen("diccionario.in", "r", stdin);
    freopen("diccionario.out", "w", stdout);
    
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		gets(a);
		A.add();	
	}
	for (int i = 0; i < m; ++i) {
		gets(a);
		int k = strlen(a);
		reverse(a, a + k);
		B.add();	
	}

    dfs(0, -1, 0);
    
	for (int i = 1; i < A.cnt; ++i) {
		ans += B.cnt - 1;
		for (int j = 0; j < 26; ++j)
			if (A.go[i][j] != -1) {
				ans -= cnt[j];
			}	
	}

	cout << ans << endl;

    return 0;
}
