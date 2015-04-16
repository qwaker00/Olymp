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

int B[111], Mib[111], tb = 0, was[111];

void ERR() {
	puts("No");
	exit(0);
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int n;
	cin >> n;	
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		int mib = 0, b = 0;
		for (int j = 0; j < s.length(); ++j) {
			if (s[j] == '(') {
				++b;
			} else {
				--b;
			}
			if (b < mib) mib = b;
		}
		Mib[i] = mib;
		B[i] = b;
		tb += b;
	}
	if (tb != 0) ERR();

	int b = 0;
	for (int i = 0; i < n; ++i) {
		int mab = int(-2e9), mabi;
		for (int j = 0; j < n; ++j)
			if (!was[j] && b + Mib[j] >= 0 && B[j] - Mib[j] > mab) {
				mab = B[j] - Mib[j];
				mabi = j;
			}
		if (mab == int(-2e9)) ERR();
		was[mabi] = 1;
		b += B[mabi];
	}
	puts("Yes");
	
    return 0;
}
