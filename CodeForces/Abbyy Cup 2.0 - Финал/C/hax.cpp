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

int n;
int b[2][11111][33], bn[2], bc[2][11111][33], p[2][11111], pseudo[11111];
int t, v;
char c, pc[2][11111];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	bn[0] = bn[1] = 1;
	pc[1][1] = 32;
	memset(pseudo, -1, sizeof(pseudo));
	for (int i = 0; i < n; i++) {
		cin >> t >> v >> c;
		t--;
		c -= 'a' - 1;

		if (b[t][v][c] && t == 0) {
			++bc[t][v][c];
			pseudo[++bn[t]] = b[t][v][c];
		} else {
			b[t][v][c] = ++bn[t];
			p[t][bn[t]] = v;
			pc[t][bn[t]] = c;
			bc[t][v][c] = 1;
		}

		LL total = 0;
		for (int end = 1; end <= bn[1]; end++) {
			int cur = end, cur1 = 1;
			LL cnt = 1;
			while (cur) {
				total += cnt;
				int tc = pc[1][cur];
				if (b[0][cur1][tc] == 0) {
					break;
				}
				cnt *= bc[0][cur1][tc];
				cur = p[1][cur];
				cur1 = b[0][cur1][tc];
			}
		}
		cout << total << endl;
	}
	
	return 0;
}
