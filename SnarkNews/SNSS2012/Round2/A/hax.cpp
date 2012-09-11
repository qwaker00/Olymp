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

    int t, n, b;
    LL a[111], c;

    cin >> t;
    while (t--) {
    	cin >> n >> b;
    	for (int i = 1; i < n; i++)	cin >> a[i];
   		a[0] = 0;
   		a[n] = 0;

   		LL ma = LL(-2e18), mi = LL(2e18);
    	for (int j = 0; j < b; j++) {
    		LL s = 0;
    		for (int i = 0; i < n; i++) {
    			cin >> c;
    			s = s * a[i] + c;
    		}
    		if (s > ma) ma = s;
    		if (s < mi) mi = s;
    	}

    	cout << ma - mi << endl;
    }

    return 0;
}
