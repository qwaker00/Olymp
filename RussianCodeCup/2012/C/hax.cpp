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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, nn;
char s[211][211];
int f[211][211], t[211][211], ans[2111111], ed[2111111];

void Min(int& x,int y) {
	if (y < x) x = y;
}

int Calc(char * a, char * b) {
	int la = strlen(a);
	int lb = strlen(b);
	a[la] = -1;
	b[lb] = -2;

	memset(f, 63, sizeof(f));
	f[la][lb] = 0;
	for (int i = la; i >= 0; i--)
		for (int j = lb; j >= 0; j--)
			{
				if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) Min(f[i - 1][j - 1], f[i][j] + 1);
				if (i > 0) Min(f[i - 1][j], f[i][j] + 1);
				if (j > 0) Min(f[i][j - 1], f[i][j] + 1);
			}
	a[la] = 0;
	b[lb] = 0;

	return f[0][0];			      
}


int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;	
	nn = n + n;
	for (int i = 0; i < n + n; ++i) {
		cin >> s[i];
		for (int j = 0; j < i; ++j) {
			t[i][j] = t[j][i] = Calc(s[i], s[j]);
//			cerr << i << " " << j << " " << t[i][j] << endl;
		} 
	}

	memset(ans, 63, sizeof(ans));
	ed[0] = 0;
	ans[0] = 0;
	for (int i = 1; i < (1 << nn); ++i) {
		ed[i] = ed[i & (i - 1)] + 1;

		if (ed[i] & 1) continue;
		for (int j = 0; j < nn; j++) if (i & (1 << j))
		for (int k = j + 1; k < nn; k++) if (i & (1 << k)) {
			Min(ans[i], max(ans[i ^ (1 << j) ^ (1 << k)], t[j][k]));
		}
//		cerr << i << " " << ans[i] << endl;
	}
	cout << ans[(1 << nn) - 1] << endl;
 
	return 0;
}
