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


int la, lb, c;
char A[1111111], B[1111111], T[1111111], tn = 0;
LL v[1111111];
int was[1111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
	gets(A);
	la = strlen(A);
	gets(B);
	lb = strlen(B);
	scanf("%d", &c);


	LL a = 0;
	for (int i = 0; i < la; ++i) a = (a * 10 + A[i] - 48) % c;

	int cyc, tail;
	v[0] = 1;
	v[1] = a % c;
	was[a % c] = 1;
	for (int i = 2; ; ++i) {
		v[i] = (v[i - 1] * a) % c;
		if (was[v[i]]) {
			cyc = i - was[v[i]];
			tail = was[v[i]] - 1;
			break;
		}
		was[v[i]] = i;
	}

	if (lb <= 7) {
		int b;
		sscanf(B, "%d", &b);

		if (b <= tail) {
			cout << v[b] << endl;
		} else {
			cout << v[tail + 1 + (b - tail - 1) % cyc];
		}
	} else {
		int ttail = ++tail;
		reverse(B, B + lb);
		while (ttail > 0) {
			T[tn++]= ttail % 10;
			ttail /= 10;
		}

		int carry = 0;
		for (int i = 0; i < lb; ++i) {
			B[i] = B[i] - T[i] + carry;
			if (B[i] < '0') {
				B[i] += 10;
				carry = -1;
			} else
				carry = 0;
		}

		LL b = 0;
		for (int i = lb - 1; i >= 0; --i) {
			b = (b * 10 + B[i] - 48) % cyc;
		}

		cout << v[tail + b] << endl;
	}

    return 0;
}
