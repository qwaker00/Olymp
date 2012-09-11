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
    freopen("dkl.in", "r", stdin);
    freopen("dkl.out", "w", stdout);
    int n, m, delta, kapa, lambda;
    cin >> delta >> kapa >> lambda;
    if (kapa <= lambda && lambda <= delta) {
    	
    } else {
    	cout << 0 << " " << 0 << endl;
    	return 0;
    }

    n = 2 * (delta + 1);
    m = ((delta + 1) * delta) + lambda;
    cout << n << " " << m << endl;

    for (int i = 0; i < delta + 1; i++)
	    for (int j = i + 1; j < delta + 1; j++)
	    	cout << i + 1 << " " << j + 1 << endl;
    for (int i = 0; i < delta + 1; i++)
	    for (int j = i + 1; j < delta + 1; j++)
	    	cout << i + 1 + delta + 1 << " " << j + 1 + delta + 1 << endl;
	for (int i = 0; i < lambda; i++) {	
		if (i + 1 >= kapa)
			cout << kapa << " " << delta + 1 + i + 1 << endl;else
			cout << i + 1 << " " << delta + 1 + i + 1 << endl;
	}

    return 0;
}
