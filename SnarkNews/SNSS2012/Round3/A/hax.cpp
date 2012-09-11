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


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    LL n;
    LL left;
    do {
    	cin >> n;

    	if (!n) break;
    	left = (LL)sqrtl(n * 2);
    	for (LL i = max(left - 5, 1ll); i <= left + 5; i++) {
    		LL s = i * (i + 1) / 2;
    		if (s > n && s - n <= i) {
    			cout << i << " " << s - n << endl;
    			break;
    		}
    	}

    } while (1);

    return 0;
}
