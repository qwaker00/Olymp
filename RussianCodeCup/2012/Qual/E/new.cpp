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

int pn, pr[1111111];
bool bad[10000011];


int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int cnt = 0;
	int next = 1000;

	int pn = 0;
	for (int i = 2; i <= 3162; i++) if (!bad[i]) {				
		pr[pn++] = i;
		for (int j = i * i; j <= 1000000; j += i) bad[j] = true;
	}
	for (int i = 3163; i <= 1000000; i++) if (!bad[i]) pr[pn++] = i;


	for (int di3 = 0; di3 < pn; di3++)
		for (int di2 = 0; di2 <= di3; di2++) {
			for (int di1 = 0; di1 <= di2; di1++) {
				int d1 = pr[di1];
				int d2 = pr[di2];
				int d3 = pr[di3];
				if ( ((d1 + d2) * (d1 + d2) - 1) % d3 != 0) continue;
				if ( ((d2 + d3) * (d2 + d3) - 1) % d1 != 0) continue;
				if ( ((d3 + d1) * (d1 + d3) - 1) % d2 != 0) continue;
				if (d3 != d1 + d2 - 1 && d3 != d1 + d2 + 1) cout << "\t\t";
				cout << "{"<<d1 << "," << d2 << "," << d3 << "},"<<endl;
				cnt++;
				if (cnt == next) {
					cerr << cnt << endl;
					next += 1000;
				}
			}
		}

	return 0;
}
