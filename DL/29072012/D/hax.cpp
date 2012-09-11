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

#define N 211111

char s[N];

struct Tg {
	int ans[4];
	int v;

	Tg() {
		ans[0] = 0;
		ans[1] = ans[2] = 1;
		ans[3] = -100500;
		v = 2;
	}

	Tg(char op, Tg& A, Tg& B) {
		if (op == 'S') {
			ans[0] = max(A.ans[0] + B.ans[0], A.ans[2] + B.ans[1] - 1);
			ans[1] = max(A.ans[1] + B.ans[0], A.ans[3] + B.ans[1] - 1);
			ans[2] = max(A.ans[0] + B.ans[2], A.ans[2] + B.ans[3] - 1);
			ans[3] = max(A.ans[1] + B.ans[2], A.ans[3] + B.ans[3] - 1);
			v = A.v + B.v - 1;
		} else
		if (op == 'P') {
			ans[0] = A.ans[0] + B.ans[0];
			ans[1] = A.ans[1] + B.ans[1] - 1;
			ans[2] = A.ans[2] + B.ans[2] - 1;
			ans[3] = A.ans[3] + B.ans[3] - 2;
			v = A.v + B.v - 2;
		}
	}
} vals[N];
int vn, stn, st[N], op, l;

int main() {
    freopen("independent.in", "r", stdin);
    freopen("independent.out", "w", stdout);

	cin >> s;
	l = strlen(s);
	for (int i = l - 1; i >= 0; --i)
		if (s[i] == 'P' || s[i] == 'S') {
			vals[vn - 2] = Tg(s[i], vals[vn - 1], vals[vn - 2]);
			--vn;
		} else
		if (s[i] == 'g') {
			vals[vn++] = Tg();
		}
	if (vn > 1) throw 2;
//	cout << vals[0].v << endl;
	cout << *max_element(vals[0].ans, vals[0].ans + 4) << endl;
    return 0;
}
