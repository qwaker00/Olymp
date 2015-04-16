#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

pair<int, int> a[2222];

int main() {
   // freopen(".in", "r", stdin);
   // freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;

    int ans;
    if (n == 0) {
    	ans = 4;
    } else
    if (n == 1) {
    	ans = 3;
    } else {
    	ans = 2;
    	for (int i = 0; i < n; ++i)
    		for (int j = i + 1; j < n; ++j) {
    			int dx = a[j].first  - a[i].first;
    			int dy = a[j].second - a[i].second;
    			{
	    			int x2 = a[j].first - dy;
    				int y2 = a[j].second + dx;
    				int x3 = x2 - dx;
    				int y3 = y2 - dy;
    				int c = 2;
	    			c -= (*lower_bound(a, a + n, make_pair(x2, y2)) == make_pair(x2, y2));
    				c -= (*lower_bound(a, a + n, make_pair(x3, y3)) == make_pair(x3, y3));
    				if (c < ans) {
    					ans = c;
    				}
    			}
    			{
	    			int x2 = a[j].first + dy;
    				int y2 = a[j].second - dx;
    				int x3 = x2 - dx;
    				int y3 = y2 - dy;
    				int c = 2;
	    			c -= (*lower_bound(a, a + n, make_pair(x2, y2)) == make_pair(x2, y2));
    				c -= (*lower_bound(a, a + n, make_pair(x3, y3)) == make_pair(x3, y3));
    				if (c < ans) {
    					ans = c;
    				}
    			}
    		}
    }
    cout << ans << endl;
	
    
    return 0;
}
