#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

#define PI 3.1415926535897932384626433832795

#define N 111111

int A[N], L[N], R[N];
int m[N];

void init() {
    memset(m, 0, sizeof(int) * N);
    memset(A, 0, sizeof(int) * N);
    memset(L, 0, sizeof(int) * N);
    memset(R, 0, sizeof(int) * N);
}

/*
inline int prev(int x) {
    return x & (x - 1);
}

inline int next(int x) {
    return ( x | (x - 1) ) + 1;
}
*/
inline void add(int x) {
    ++x;

    if (++A[x] == 1) {
        int y = x;
        while (y < N) {
            ++L[y];
            y = (y | (y - 1)) + 1;
        }
        y = x;
        while (y) {
            ++R[y];
            y &= y - 1;
        }
    }
}

inline void del(int x) {
	++x;

    if (--A[x] == 0) {
        int y = x;
        while (y < N) {
            --L[y];
            y = (y | (y - 1)) + 1;
        }
        y = x;
        while (y) {
            --R[y];
            y &= y - 1;
        }
    }
}

inline int mex() {
    int cur = 1, nxt = (cur | (cur - 1)) + 1 ;
    while (R[cur] == nxt - cur) cur = nxt, nxt = (cur | (cur - 1)) + 1;
    if (A[cur] == 0) return cur - 1;
    int step = (cur | (cur - 1)) + 1 - cur;
    while (step > 1) {
        step >>= 1;
        if (L[cur + step] == step) cur += step;
    }
	return cur;
}

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
		
	int T;
	scanf("%d\n", &T);

    FILE* f = fopen("1.err", "w");
	for (int __it = 1; __it <= T; ++__it) {
		int n, k, a, b, c, r;
		scanf("%d%d", &n, &k);
		scanf("%d%d%d%d", &a, &b, &c, &r);
        init();

		m[0] = a;
		for (int i = 1; i < k; ++i) m[i] = (LL(b) * m[i - 1] + c) % r;

        queue<int> q;
		for (int i = 0; i < k; ++i) if (m[i] <= k) ++S[m[i]];
        for (int i = 0; i <= k; ++i) if (S[i] == 0) q.push(i);

		int cur = 0;
		int ans = 0;
        int cp = 1000000;
        cerr << "ok" << endl;

		for (int i = k; i < n; ++i) {
			ans = q.top(); q.pop();


			if (m[cur] <= k) del(m[cur]);
			add(ans);
			m[cur] = ans;
			if (++cur == k) cur = 0;

//            fprintf(f, "%d\n", ans);
//            fprintf(stderr, "%d\n", i);
            if (i == cp) { cerr << i << endl; cp += 1000000; }
		}

		printf("Case #%d: %d\n", __it, ans);
	}
    cerr << clock() << endl;
	
	return 0;
}
                   