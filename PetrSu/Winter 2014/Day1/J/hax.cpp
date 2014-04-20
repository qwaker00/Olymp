#include <iostream>
#include <string>
#include <cstdio>
#include <memory.h>
#include <string.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <climits>

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double LD;
typedef long double ld;
const LD PI = 3.1415926535897932384626433832795;

template<typename T>
T sqr(const T& x) { return x * x; }

using namespace std;

ll doit(ll a, ll b, ll c) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	//cerr << a << " " << b << " " << c << " " << endl;

	if (a == 1) return b + c + doit(0, b, c);
	if (b == 1) return c + doit(0, 0, c);
	if (c == 1) return 0;

	if (a == 0 && b == 0 && c == 0) return 0;

	if (a == 0 && b == 0) {
		return c - 1 + c - 2;
	}

	if (a == 0) {
		return 6 + (b + c - 4) * 4;
	}

	return 15 + (a + b + c - 6) * 6;
}

int main() {
	//freopen("in","r", stdin);
	//freopen(".out","w", stdout);

	int a, b, c;
	while (scanf("%d", &a) == 1) {
		scanf("%d%d", &b, &c);
	
		cout << doit(a, b, c) << endl;
	}


	return 0;
}