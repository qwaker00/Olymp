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

vector<LL> ans;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    

    for (int i = 1; i <= 1000000000; ++i) {
    	int x = i, y = 0;
    	while (x > 0) {
    		y = y * 10 + x % 10;
    		x /= 10;
    	}
    	if (i != y) continue;

    	LL xx = LL(i) * i, ii = xx, yy = 0;
    	while (xx > 0) {
    		yy = yy * 10 + xx % 10;
    		xx /= 10;
    	}
    	if (yy != ii) continue;

    	cerr << ii << endl;
    	ans.push_back(ii);
    }

	int T;
	cin >> T;
	for (int __it = 1; __it <= T; ++__it) {
		LL A, B;
		cin >> A >> B;
		vector<LL>::iterator i1 = lower_bound(ans.begin(), ans.end(), A);
		vector<LL>::iterator i2 = upper_bound(ans.begin(), ans.end(), B);
		printf("Case #%d: %d\n", __it, i2 - i1);
	}	    
	    
    
    return 0;
}
