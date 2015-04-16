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

int pr[111], pn;
int n;
int take[111];

struct tlong {
	int data[30], len;

	tlong() : len(1) { memset(data, 0, sizeof(data)); };

	void operator*=(int x) {
		int carry = 0;
		for (int i = 0; i < len; ++i) {
			carry += data[i] * x;
			data[i] = carry % 10000;
			carry /= 10000;
		}
		while (carry) {
			data[len++] = carry % 10000;
			carry /= 10000;
		}
	}

	void operator-=(const tlong& b) {
		int carry = 0;
		for (int i = 0; i < len; ++i) {
			carry += data[i] - b.data[i];
			if (carry < 0) {
				data[i] = carry + 10000;
				carry = -1;
			} else {
				data[i] = carry;
				carry = 0;
			}
		}
		while (len > 1 && data[len - 1] == 0) --len;
	}

	bool operator<(const tlong& b) const {
		if (len > b.len) return false;
		if (len < b.len) return true;
		for (int i = len - 1; i >= 0; --i)
			if (data[i] != b.data[i])
				return data[i] < b.data[i];
	    return false;
	}

	void out() const {
		printf("%d", data[len - 1]);
		for (int i = len - 2; i >= 0; --i) printf("%04d", data[i]);
	}
};

bool any = false;
tlong ans, ansa;



inline void update() {
	tlong a, b;
	a.data[0] = 1;
	b.data[0] = 1;
	for (int i = 0; i < n; ++i) {
		if (take[i]) {
			a *= pr[i];
		} else
			b *= pr[i];
	}
	if (a < b) {
		swap(a, b);
	}
	a -= b;
	if (!any || a < ans) {
		ans = a;
		ansa = b;
		any = true;
	}
}

void gen(int c, int i) {
	if (c + c > n) return;

	update();

	for (int j = i; j < n; ++j) {
		take[j] = 1;
		gen(c + 1, j + 1);
		take[j] = 0;
	}
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

	for (int i = 2; pn < 30; ++i) {
		bool prm = 1;
		for (int j = 0; j < pn; ++j) if (i % pr[j] == 0) {
			prm = 0;
			break;
		}
		if (prm) {
			pr[pn++] = i;
		}		
	}
	cerr << pn << endl;

	cin >> n;
	gen(0, 0);
	cout << "\"";
	ansa.out();
	cout << "\",";
	cout << endl;

    return 0;
}
