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

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int A, B;
	cin >> A >> B;
	for (int C = 1; C <= 400; ++C) {
		if (C * C == A * A + B * B) {
			puts("YES");
			return 0;
		}
		if (A * A == C * C + B * B) {
			puts("YES");
			return 0;
		}
		if (B * B == A * A + C * C) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
    
    return 0;
}
