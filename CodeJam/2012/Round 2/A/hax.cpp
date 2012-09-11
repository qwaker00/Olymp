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

int f[111111], T;
int d[111111], l[111111], p[1111111];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		int n, D;

		cin >> n;
		for (int i = 0; i < n; i++) cin >> d[i] >> l[i];
		cin >> D;

		bool good = false;
		memset(f, 128, sizeof(f));
		f[0] = d[0];
		for (int i = 0; i < n; i++) if (f[i] > 0) {
			if (d[i] + f[i] >= D) {
				good = true;
				break;
			}
			for (int j = i + 1; j < n && d[i] + f[i] >= d[j]; j++) {
				if (f[j] < min(l[j], d[j] - d[i])) {
					f[j] = min(l[j], d[j] - d[i]);
					p[j] = i;
				}
			}
		} else if (f[i] == 0) throw 666;

		cout << "Case #" << _ << ": " << ( good ? "YES": "NO") << endl;
//		if (d[n-1] + f[n-1] >= D) {
//			for (int k = n-1;k>0;) {
//				cout << d[k] << " " << l[k] << endl;
//				k=p[k];
//			}
//			cout << d[0] << " " << l[0] << endl;
//		} else {
//			cout << n << endl;
//			for (int i=0;i<n;i++) cout << d[i] << " " << l[i] << endl;
//			cout << D << endl;
//		}
	}

	return 0;
}
