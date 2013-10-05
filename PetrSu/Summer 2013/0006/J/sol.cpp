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
	int t;
	int n;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		if (n & 1) {
			puts("NIE");
			continue;
		}	

		int turn = 0;
		int last = -1;
		while (!(n & 1)) {
			n >>= 1;
			last = n;
			turn ^= 1;
		}

		if (n == last) {
			puts(turn == 0 ? "NIE" : "TAK");
		} else {
			puts(turn == 1 ? "NIE" : "TAK");
		}
	}	
	
	return 0;
}
