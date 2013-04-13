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
#include <unordered_set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int k, n;
unsigned a1, a2, a3, a4, a[111111];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    scanf("%d%d", &n, &k);
    for (int i =0; i < n; ++i) {
    	scanf("%u.%u.%u.%u", &a1, &a2, &a3, &a4);
    	a[i] = (a1 << 24) + (a2 << 16) + (a3 << 8) + a4;
    }

    for (int i = 1; i <= 32; ++i) {
    	unsigned mask = -(1u << (32 - i));
    	unordered_set<unsigned> s; 
    	for (int j = 0; j < n; ++j) {
    		s.insert( a[j] & mask );
    	}
    	if ((int)s.size() == k) {
    		printf("%u.%u.%u.%u\n", (mask >> 24) & 255, (mask >> 16) & 255, (mask >> 8) & 255, mask & 255);
    		return 0;
    	}
    }
    cout << -1 << endl;
	    
    return 0;
}
                                 