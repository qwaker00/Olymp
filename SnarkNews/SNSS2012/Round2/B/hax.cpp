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

int D[1111111];
int q[1111111][7], dd[1111111], w[7], q1, q2, x;
int n;

inline int hash(int* a) {
	int h = 0;
	for (int i = 0; i < n; i++) h = h * 7 + a[i];
	return h;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    cin >> n;

    memset(D, 127, sizeof(D));

    for (int i = 0; i < n; i++) {
    	cin >> x;
    	q[0][x - 1] = i;
    }

    dd[0] = 0;
    D[hash(q[0])] = 0;
    q1++;

    while (q1 > q2) {
    	int* a = q[q2];

    	bool end = true;
		for (int j = 0; j < n; j++) if (a[j] != j) {
			end = false;
			break;
		}
		if (end) {
			cout << dd[q2] << endl;
			return 0;
		}

    	memset(w, 0, sizeof(w));
    	for (int i = 0; i < n; i++) {
    		if (w[ a[i] ]) continue;
			w[a[i]] = 1;

			if (a[i] != 0 && !w[a[i] - 1]) {
				memcpy(q[q1], q[q2], 28);
				q[q1][i] = a[i] - 1;
				int h = hash(q[q1]);
				if (D[h] > dd[q2] + 1) {
					D[h] = dd[q1] = dd[q2] + 1;
					++q1;					
				}
			}

			if (a[i] != n - 1 && !w[a[i] + 1]) {
				memcpy(q[q1], q[q2], 28);
				q[q1][i] = a[i] + 1;
				int h = hash(q[q1]);
				if (D[h] > dd[q2] + 1) {
					D[h] = dd[q1] = dd[q2] + 1;
					++q1;
				}
			}
    	}

    	++q2;
    }

	cout << -1 << endl;

    return 0;
}
