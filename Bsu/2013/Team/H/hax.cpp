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


int main() {
    freopen("square-free.in", "r", stdin);
    freopen("square-free.out", "w", stdout);
    
	int n;
	cin >> n;

	LL a;
	while (n--) {
		cin >> a;

		bool cool = true;

		for (LL i = 2; i <= 12000; ++i) {
			if (i * i > a) break;
			if (a % (i * i) == 0) {
				cool = false;
				break;
			} 
		}

		if (!cool) { 
			printf("%I64d is not square-free\n", a);
			continue;
		}

		for (LL i = 2; i <= 12000; ++i) {
			if (a % i == 0) {
				LL b = a / i;

				LL s = sqrt(double(b) + 1e-5);
				while (s * s < b) ++s;

				if (s * s == b && s > 1) {
					cool = false;
					break;
				}
			}
		}

		if (!cool) { 
			printf("%I64d is not square-free\n", a);
		} else {
		    printf("%I64d is square-free\n", a);
		}
	}
    
    return 0;
}
