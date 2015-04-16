#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

LL gcd(LL x, LL y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	LL n;
	int m;
	cin >> n >> m;

	for (int i = m - 1; i >= 0; --i) {		
		if (n > 0) {
			LL C = 1, CC;
			int UP = i + 1;
			int LO = i + 1;


			if (UP == 2) {
				int sq = int(sqrt(2*n) - 100);
				if (sq > LO) {
					LO = sq;
					C = LL(LO) * (LO - 1) / 2;
				}
			} else
			if (UP == 1) {
				LO = n;
				C = n;
			}

			while (1) {
				if (C == n) break;

				if (double(C) * (LO + 1) / (LO - UP + 1) > 5e16) break;

				if (double(C) * (LO + 1) < 5e18) {
					CC = C * (LO + 1) / (LO - UP + 1);
				} else {
					LL x = C;
					LL y = LO + 1;
					LL z = LO - UP + 1;
					LL g = gcd(x, z);
					if (g > 1) {
						x /= g;
						z /= g;
					}
					CC = x * (y / z);
				}

				if (CC > n) break;
				C = CC;
				++LO;
			}
			printf("%d ", LO);
			n -= C;
		} else {
			printf("%d ", i);
		}
	}
	puts("");
	    
    return 0;
}
