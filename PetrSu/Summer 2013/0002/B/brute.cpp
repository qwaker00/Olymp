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

const int N = 47;
int a[N][N], b[N][N], c[N][N];

char w[311];

int main() {
	freopen("xoring.in", "r", stdin);
	freopen("xoring.out", "w", stdout);
	
	w[0] = ' ';
	w[1] = 'x'; 

	for (int i = 0; i < N; ++i)
		for (int j = 0; j <= i; ++j) {
			if (i == j || i == j + 1) a[i][j] = 1; 
		}

	for (int i = 0; i < N; ++i) b[i][i] = 1;

	for (int iter = 0; iter <= N + 1; ++iter) {
		cout << iter << endl;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) cout << w[b[i][j]];
			cout << endl;
		}

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				int sum = 0;
				for (int k = 0; k < N; ++k) {
					sum += b[i][k] * a[k][j];
				}
				c[i][j] = sum & 1;
			}
		memcpy(b, c, sizeof(c));
	}

	
	return 0;
}
