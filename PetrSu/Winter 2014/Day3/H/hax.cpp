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

int n, T;
char s[1111111];

int main() {
//	freopen(".in","r", stdin);
//	freopen(".out","w", stdout);

	int T;
	scanf("%d\n", &T);
	while (T--) {
		gets(s);
		n = strlen(s);

		int bk0 = 0, bk1 = 0;
		int k0 = 0, k1 = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (k0) {
					--k0;
					++k1;
				} else {
					++bk0;
					++k1;
				}
			} else {
				if (k1) {
					--k1;
					++k0;
				} else {
					++bk1;
					++k0;
				}
			}
		}
		priority_queue<int> q0, q1;
		for (int i = 0; i < bk0; ++i) q0.push(0);
		for (int i = 0; i < bk1; ++i) q1.push(0);
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				int x = q0.top(); q0.pop();
				q1.push(x - 1);
			} else {
				int x = q1.top(); q1.pop();
				q0.push(x - 1);
			}
		}
		int ans = 0;
		while (!q1.empty()) {
			ans = max(ans, -q1.top());
			q1.pop();
		}	
		while (!q0.empty()) {
			ans = max(ans, -q0.top());
			q0.pop();
		}
		printf("%d %d\n", bk1 + bk0, ans);
	}

	return 0;
}