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


int main() {
	freopen("embedding.in", "r", stdin);
	freopen("embedding.out", "w", stdout);

	int n; scanf("%d", &n);
	while (n) {
		if (n == 3) {
			puts("1 2 3 4 5 6");
			puts("1 4 5 3 2 6");
			puts("2 6 1 3 4 5");
			scanf("%d", &n);
			continue;
		}
		if (n == 4) {
			puts("1 2 3 4 5 6 7 8");
			puts("1 6 7 8 5 3 4 2");
			puts("4 1 7 5 3 8 2 6");

			scanf("%d", &n);
			continue;
		}

		if (n & 1) {
			for (int i = 1; i <= n + n; ++i) printf("%d ", i);
			puts("");

			printf("1 ");
			for (int i = n + 2; i <= n + n; ++i) printf("%d ", i);
			printf("%d ", n + 1);
			for (int i = 3; i <= n; ++i) printf("%d ", i);
			puts("2");

			vector<int> a;
			for (int i = 1; i <= n; i += 2) a.push_back(i);
			for (int i = 2; i <= n + 1; i += 2) a.push_back(i);
            for (int i = 0; i < a.size(); ++i) printf("%d ", a[i]);

            for (int i = 1; i + 1 < a.size(); ++i) {
            	if (a[i] == n) {
            		printf("%d ", n + 2);
            	} else {
            		printf("%d ", a[i] + n + 1);
            	}
            }
            puts("");
		} else {
		    for (int i = 1; i <= n + n; ++i) printf("%d ", i);
			puts("");

			printf("1 ");
			for (int i = n + 2; i <= n + n; ++i) printf("%d ", i);
			printf("%d ", n + 1);
			for (int i = 3; i <= n; ++i) printf("%d ", i);
			puts("2");

			map<int, int> q;
			vector<int> a;

			int k = n / 2;
			int left = 1, right = n;
			while (left != k + 1) {
				a.push_back(left);
				a.push_back(right);
				++left; --right;
			}
			a.pop_back();
			a.push_back(n + 1);

			a.push_back(n + k + 1);
			for (int i = 2; i <= n; ++i) {
				if (i == n) {
					q[i] = n + 2;
				} else {
					q[i] = i + n + 1;
				}
			}	
			q[k] = q[k] + 1;
			q[n + 1] = k + 1;

		   for (int i = 0; i < a.size(); ++i) printf("%d ", a[i]);
		   for (int i = 1; i + 1 < a.size(); ++i) printf("%d ", q[ a[i] ]);
		   puts("");
		}

		scanf("%d\n", &n);
	}
		
	return 0;
}
