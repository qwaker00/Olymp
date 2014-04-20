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

const int N = 1111111;

bool alive[N];

priority_queue<pair<int, int> > qq;

char w[111];

inline void readq(bool& a, bool& b) {
	char c= getchar();
	while (c != '+' && c != '-') c= getchar();
	a = (c == '+');

	c = getchar();
	b = (c == 'L');
}

inline void readi(int& x) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	x = 0;
	do {
		x = x * 10 + c - '0';
		c = getchar();
	} while (c >= '0' && c <= '9');
}

int A[3333222];
int B[3333222];

inline void recalc(int L, int C, int R) {
	if (L < C) {
		B[C - 1] = A[C - 1];
		for (int i = C - 2; i >= L; --i) {
			B[i] = min(B[i + 1], A[i]);
		}
	}
	if (R > C) {
		B[C] = A[C];
		for (int i = C + 1; i < R; ++i) {
			B[i] = min(B[i - 1], A[i]);
		}
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int L = 1500000;
    int R = L;
    int C = L;

	int t;
	readi(t);
	
	for (int iter = 1; iter <= t; ++iter) {
		bool p, l;
		readq(p, l);

		
		if (p) {
			int x;
			readi(x);

			if (l) {
				A[--L] = x;
				if (L + 1 == C)
					B[L] = A[L];else
					B[L] = min(B[L + 1], A[L]);
			}
			else {
				A[R++] = x;
				if (R - 1 == C)
					B[R - 1] = A[R - 1];else
					B[R - 1] = min(B[R - 2], A[R - 1]);
			}
		} else {
        	if (l) { 
        		if (L == C) {
        			C = (L + R + 1) / 2;
					recalc(L, C, R);
        		}
        		++L;
            } else {
				if (R == C) {
					C = (L + R) / 2;
					recalc(L, C, R);
				}
				--R;
            }
		}

		int ans = (int)2e9;
		if (L < C) ans = min(ans, B[L]);
		if (R > C) ans = min(ans, B[R - 1]);
		if (ans > 1e9 + 2) ans = -1;
		printf("%d\n", ans);

	}

//	cerr << clock() << endl;
    
    return 0;
}
