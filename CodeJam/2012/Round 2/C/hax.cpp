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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n, a[11111], p[11111];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	int T;
	cin >> T;
	for (int _=0;_<T;_++) {

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
		a[i] --;
		p[i] = i;
	}
	p[n - 1] = n - 1;

	bool good = false;
	do {
		good = true;
		for (int i = 0; i < n - 1; i++) {			
			for (int k = i + 1; k < n ; k++)
				if (k < a[i]) {
					if (p[k] * (a[i] - i) >= p[i] * (a[i] - i)+ (k - i) * (p[a[i]] - p[i])) {
						good = false;
						break;
					}
				} else
				if (k > a[i]) {
					if (p[k] * (a[i] - i) > p[i] * (a[i] - i) + (k - i) * (p[a[i]] - p[i])) {
						good = false;
						break;
					}					
				}
		}
		if (good) break;
	} while (next_permutation(p, p + n));

	printf("Case #%d:", _ + 1);
	if (!good) {
		p[n-1] += p[n-1];
		p[0] -= p[n-1];
	good = false;
	do {
		good = true;
		for (int i = 0; i < n - 1; i++) {			
			for (int k = i + 1; k < n ; k++)
				if (k < a[i]) {
					if (p[k] * (a[i] - i) >= p[i] * (a[i] - i)+ (k - i) * (p[a[i]] - p[i])) {
						good = false;
						break;
					}
				} else
				if (k > a[i]) {
					if (p[k] * (a[i] - i) > p[i] * (a[i] - i) + (k - i) * (p[a[i]] - p[i])) {
						good = false;
						break;
					}					
				}
		}
		if (good) break;
	} while (next_permutation(p, p + n));
		if (!good) {
			cout << " Impossible" << endl;
		} else{
			for (int i = 0; i < n; i++) cout << " " << p[i] + 1;
			cout << endl;
		}
	} else{
		for (int i = 0; i < n; i++) cout << " " << p[i] + 1;
		cout << endl;
	}

	}

	return 0;
}
