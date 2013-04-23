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
       
#define N 111111

int n, m, h[N*5], hn, q[N];
struct Tp {
    int x1, x2, y;

    bool operator<(const Tp& b) const {
        return y < b.y;
    }
} a[N];
int v[N*15], f[N];

void InitTree() {
    memset(v, -1, sizeof(v));
}

void PushColor(int x) {
	if (v[x] != -2) {
		v[x * 2] = v[x * 2 + 1] = v[x];
		v[x] = -2;
	}
}
 
void SetColor(int x, int tl, int tr, int l, int r, int color) {
	if (l > r) return;
	if (l == tl && tr == r) v[x] = color; else {
		PushColor(x);
		int tm = (tl + tr) / 2;
		SetColor(x * 2, tl, tm, l, min(r, tm), color);
		SetColor(x * 2 + 1, tm + 1, tr, max(l, tm+1), r, color);
	}
}
 
int GetColor(int x, int tl, int tr, int pos) {
	if (v[x] != -2) return v[x];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return GetColor(x * 2, tl, tm, pos);
	else
		return GetColor(x * 2 + 1, tm + 1, tr, pos);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d" ,&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i].x1, &a[i].x2, &a[i].y);
        h[hn++] = a[i].x1;
        h[hn++] = a[i].x2;
        h[hn++] = a[i].x1 - 1;
        h[hn++] = a[i].x2 + 1;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &q[i]);
        h[hn++] = q[i];
    }

    sort(h, h + hn);
    hn = unique(h, h + hn) - h;
    sort(a, a + n);

    InitTree();

    for (int i = 0; i < n; ++i) {
        int hl = lower_bound(h, h + hn, a[i].x1 - 1) - h;
        int hr = lower_bound(h, h + hn, a[i].x2 + 1) - h;
        int l = GetColor(1, 0, hn - 1, hr);
        int r = GetColor(1, 0, hn - 1, hl);
        int fl = (l != -1) ? f[l] + 1 : 1;
        int fr = (r != -1) ? f[r] + 1 : 1;
        f[i] = max(fl, fr);
        SetColor(1, 0, hn - 1, hl + 1, hr - 1, i);
    }

    for (int i = 0; i < m; ++i) {
        int l = GetColor(1, 0, hn - 1, lower_bound(h, h + hn, q[i]) - h);
        int fl = (l != -1) ? f[l]: 0;
        printf("%d\n", fl);
    }
    
    return 0;
}
