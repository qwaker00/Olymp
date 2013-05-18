#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

int ed[1111];
int a[11];


int main() {
    freopen("jewelry.in", "r", stdin);
    freopen("jewelry.out", "w", stdout);
    
    for (int i= 0; i < 9; ++i)
		scanf("%d", &a[i]);


	for (int i = 1; i < 512; ++i) {
		ed[i] = ed[i & (i - 1)] + 1;
		if (ed[i] != 7) continue;

		LL sum = 0;
		for (int j = 0; j < 9; ++j) if (i & (1 << j)) {
			sum += a[j];
		}
		if (sum == 100) {
			for (int j = 0; j < 9; ++j) if (i & (1 << j)) {
				cout << a[j] << endl;
			}
			return 0;			
		}		
	}	 
	throw 1;
    
    return 0;
}

