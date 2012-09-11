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
#include <sstream>
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


char s[1111111];
int a[11111];

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	while (gets(s)) {
		istringstream ss(s);
		int sum = 0;
		for (int i =0 ;  i < 12; i++) {
			ss >> a[i];
			sum += a[i];
		}			
		if (sum  == 0) break;
		sort(a, a + 12);
		puts( (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] &&
		       a[4] == a[5] && a[5] == a[6] && a[6] == a[7] &&
		       a[8] == a[9] && a[9] == a[10] && a[10] == a[11]) ? "yes" : "no");
	}

	return 0;
}
