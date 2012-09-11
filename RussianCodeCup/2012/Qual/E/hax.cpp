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

int pn, pr[11111111];
bool bad[11000011];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	int n;
	cin >> n;
	int pn = 0;
	for (int i = 2; i <= 3162; i++) if (!bad[i]) {				
		pr[pn++] = i;
		for (int j = i * i; j <= 11000000; j += i) bad[j] = true;
	}
	for (int i = 3163; i <= 11000000; i++) if (!bad[i]) pr[pn++] = i;

	int cnt = 0;
	for (int i = 0; i < pn; i++) {
		int d1 = pr[i];
		int d2 = pr[i];
		int d3 = d1 + d2 - 1;
		if (!bad[d3]) {
			n--;
			if (n == 0) {
				cout << d1 << " " << d2 << " " << d3 << endl;
				break;
			}
		}

		d3 = d1 + d2 + 1;
		if (!bad[d3]) {
			n--;
			if (n == 0) {
				cout << d1 << " " << d2 << " " << d3 << endl;
				break;
			}
		}
	}

/*	int cnt = 0;
	int next = 1000;
	for (int di3 = 0; di3 < pn; di3++)
		for (int di2 = 0; di2 <= di3; di2++) {
			for (int di1 = 0; di1 <= di2; di1++) {
				int d1 = pr[di1];
				int d2 = pr[di2];
				int d3 = pr[di3];
				if ( ((d1 + d2) * (d1 + d2) - 1) % d3 != 0) continue;
				if ( ((d2 + d3) * (d2 + d3) - 1) % d1 != 0) continue;
				if ( ((d3 + d1) * (d1 + d3) - 1) % d2 != 0) continue;
				cout << "{"<<d1 << "," << d2 << "," << d3 << "},"<<endl;
				cnt++;
				if (cnt == next) {
					cerr << cnt << endl;
					next += 1000;
				}
			}
		}
	*/
	return 0;
}
