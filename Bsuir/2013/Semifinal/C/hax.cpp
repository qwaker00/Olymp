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

int xl[] = {0, 192, 384, 384, 192, 0, 0};
int yl[] = {0, 206, 206, 0, 0, 0, 206};


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int x, y;
	cin >> x >> y;
	int w = 384;
	int h = 206;

	char dir;
	int lus;

    cin >> dir >> lus;

    cout.precision(12);
    cout << fixed;
    if (dir == 'U') {
    	if (lus == 6 || lus == 1 || lus == 2) cout << -1 << endl;else {
    		int xx = xl[lus];
    		int yy = yl[lus] + h + h;

    		double ang = atan2(yy - y, xx - x);
    		if (ang < 0) ang += PI * 2;
    		cout << ang / PI * 180 << endl;
    	}
    } else
    if (dir == 'D') {
    	if (lus == 5 || lus == 4 || lus == 3) cout << -1 << endl;else {
    		int xx = xl[lus];
    		int yy = yl[lus] - h - h;

    		double ang = atan2(yy - y, xx - x);
    		if (ang < 0) ang += PI * 2;
    		cout << ang / PI * 180 << endl;
    	}    	
    } else
    if (dir == 'R') {
    	if (lus == 2 || lus == 3) cout << -1 << endl;else {
    		int xx = w + w - xl[lus];
    		int yy = yl[lus];

    		double ang = atan2(yy - y, xx - x);
    		if (ang < 0) ang += PI * 2;
    		cout << ang / PI * 180 << endl;
    	}    	
    } else
    if (dir == 'L') {
    	if (lus == 6 || lus == 5) cout << -1 << endl;else {
    		int xx = -xl[lus];
    		int yy = yl[lus];

    		double ang = atan2(yy - y, xx - x);
    		if (ang < 0) ang += PI * 2;
    		cout << ang / PI * 180 << endl;
    	}    	
    }
    
    return 0;
}
