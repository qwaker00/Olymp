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
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

const double PI = 3.1415926535897932384626433832795;
template<typename T>
T sqr(T x) { return x * x; }

using namespace std;

int was[55][55];
int ans[55][55];

bool win(int n1, int n2, int k1, int k2) {
	 if (was[n1][n2]) return ans[n1][n2];
	 was[n1][n2] = 1;
	 for (int i = 1; i <= k1; ++i) {
	 	if (i <= n1 && !win(n2, n1 - i, k2, k1)) {
	 		ans[n1][n2] = 1;
	 		return 1;
	 	}
	 }	
	 ans[n1][n2] = 0;
	 return 0;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

	int n1, n2, k1, k2;	
	cin >> n1 >> n2 >>k1 >> k2;
	if (win(n1, n2, k1, k2)) {
		puts("First");
	} else {
		puts("Second");
	}
	
    return 0;
}

