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

const int N = 222222;
int a[2000111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
	scanf("%d", &n);   	 
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[x] = x;
	}
	for (int i = 1; i <= 2000000; ++i) {
		a[i] = max(a[i], a[i - 1]);
	}

	int ans = 0;
	for (int i = 1; i <= 1000000; ++i) {
		if (a[i] == i) {
			for (int j = i + i; j < 2000111; j += i)
				ans =  max(ans, a[j - 1] % i);
		}
	}
	cout << ans << endl;

    return 0;
}
