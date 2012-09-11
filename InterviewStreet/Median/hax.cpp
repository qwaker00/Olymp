#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

using namespace std;

LL v[222222];
int vn = 0;

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	LL x;
	int n;
	char ch;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ch >> x;

		bool ok = true;
		if (ch == 'a') {
			int p = upper_bound(v, v + vn, x) - v;
//			memmove(v + p + 1, v + p, (vn - p) << 3);
			
			for (int j = vn; j > p; --j) v[j] = v[j - 1];
			v[p] = x;

			++vn;
		} else
		if (ch == 'r') {
			int p = lower_bound(v, v + vn, x) - v;
			if (p < vn && v[p] == x) {
//				memcpy(v + p, v + p + 1, (vn - p - 1) << 3);

				for (int j = p; j < vn; ++j) v[j] = v[j + 1];

				--vn;
			} else ok = false;
		}

		if (!ok || vn == 0) {
			cout << "Wrong!" << endl;
		} else {
			if (vn & 1) { 
				cout << v[vn >> 1] << endl;
			} else {
				x = v[vn >> 1] + v[(vn >> 1) - 1];
				if (x & 1) {
					cout << (x / 2) << ".5" << endl;
				} else {
					cout << (x / 2) << endl;
				}
			}
		}
	}

	return 0;
}
