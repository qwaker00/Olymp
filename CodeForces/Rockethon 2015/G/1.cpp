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

int p[11];
int sum, c;
	int n, k;

void rec(int k) {
	if (k == 0) {
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
				if (p[i] > p[j]) 
					++sum;
		++c;
		return;
	}
	for (int i= 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			reverse(p + i, p + j + 1);
			rec(k - 1);
			reverse(p + i, p + j + 1);
		}
	}
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> p[i]; 
	rec(k);
	cout.precision(12);
	cout << fixed;
	cout << double(sum) / c << endl;
	
    return 0;
}
