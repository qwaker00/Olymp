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

double hit[128][128];
char s[111111];
int n;

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	while (T--) {
		gets(s);
		n = strlen(s);

		memset(hit, 0, sizeof(hit));
		for (int i = 0; i < n; i += 4) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					++hit[ s[i + j] ][ s[i + k] ];
				}
			}
		}

		vector<double> all;
		for (int i = 0; i < 128; ++i)
			for (int j = 0; j < 128; ++j) if (hit[i][j] > 0) {
				//hit[i][j] /= hit[i][i] * hit[j][j];
				all.push_back(hit[i][j]);
			}
		sort(all.begin(), all.end());

		double M = 0;
		for (int i = 0; i < all.size(); ++i) M += all[i];
		M /= all.size();
		double D = 0;
		for (int i = 0; i < all.size(); ++i) D += (all[i] - M) * (all[i] - M);
		D /= all.size();
		D = sqrtl(D);

		random_shuffle(s, s + n);
		memset(hit, 0, sizeof(hit));
		for (int i = 0; i < n; i += 4) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					++hit[ s[i + j] ][ s[i + k] ];
				}
			}
		}

		all.clear();
		for (int i = 0; i < 128; ++i)
			for (int j = 0; j < 128; ++j) if (hit[i][j] > 0) {
//				hit[i][j] /= hit[i][i] * hit[j][j];
				all.push_back(hit[i][j]);
			}
		sort(all.begin(), all.end());

		double M1 = 0;
		for (int i = 0; i < all.size(); ++i) M1 += all[i];
		M1 /= all.size();
		double D1 = 0;
		for (int i = 0; i < all.size(); ++i) D1 += (all[i] - M) * (all[i] - M);
		D1 /= all.size();
		D1 = sqrtl(D1);

		if (D / D1 > 1.08) {
			puts("block");
		} else {
			puts("random");
		}
//		cout << M / M1 << endl;
//		cout << D / D1 << endl;
//		cout << endl;
	}
	
	return 0;
}
