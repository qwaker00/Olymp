#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 33003;
const int M = 200001;

ll balance[M];
ll coef[M];
int a[N], b[N];
char w[M];

int main() {
	freopen("xoring.in", "r", stdin);
	freopen("xoring.out", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	cin.ignore();
	
	gets(w);
	int l = strlen(w);

	ll cf = -1;
	ll cur = 0;
	int sz = 0;
	for (int j = 0; j < l; ++j) {
		if (w[j] == 'L') {
			++cur;
		} else if (w[j] == 'R') {
			--cur;		
		} else if (w[j] >= '0' && w[j] <= '9') {
			if (cf == -1) {
				cf = w[j] - '0';
			} else {
				cf = cf * 10 + w[j] - '0';
			}
		} else if (w[j] == '(') {
			balance[sz] = cur;
			coef[sz] = cf;
			cf = -1;
			cur = 0;
			sz++; 
		} else {
			cur = balance[sz - 1] + coef[sz - 1] * cur;
			sz--;
		}
	}

	if (cur == 0) {
		for (int i = 0; i < n; ++i) printf("%d ", a[i]);
		puts("");
		return 0;
	}

	if (cur > 0) {
		for (int i = 0; i < 64; ++i)
			if (cur & (1LL << i)) {
				ll sub = (1LL << i);
				for (int j = 0; j < n; ++j) {
					b[j] = a[j];
					if (j >= sub) b[j] ^= b[j - sub];
				}

				memcpy(a, b, sizeof(b));
			}

		for (int i = 0; i < n; ++i) printf("%d ", a[i]);
		puts("");
		return 0;
	}

	cur = -cur;
	for (int i = 0; i < 64; ++i)
			if (cur & (1LL << i)) {
				ll sub = (1LL << i);
				for (int j = 0; j < n; ++j) {
					b[j] = a[j];
					if (j >= sub) b[j] ^= a[j - sub];
				}

				memcpy(a, b, sizeof(b));
			}

	for (int i = 0; i < n; ++i) printf("%d ", a[i]);
	puts("");

	return 0;
}
