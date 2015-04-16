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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int main() {
    double x, y, dx, dy;
    cin >> x >> y >> dx >> dy;
	int p = 35;
	int d = 10;
	int p2 = 35;
	int d2 = 10;
   	vector<int> dies = {-p, -p-d, -p-2*d, -p-3*d, -p-4*d, -p-5*d, 
   	                     p2, p2+d2,  p2+2*d2,  p2+3*d2,  p2+4*d2,  p2+5*d2};
	for (int i = 0; i < 6; ++i) cout << dies[i] + 360 << " ";
	cout << endl;
	for (int i = 0; i < 6; ++i) cout << dies[i+6] << " ";
	cout << endl;

	while (1) {
		int id;
		if (x * dy > y * dx)
			id = 2;
		else
			id = 1;
		cout << id << endl;

		double deg;
		string ver;
		cin >> deg;		
		cin >> ver;
		if (ver == "Yes") break;

	    cin >> x >> y >> dx >> dy;
	}
    
    return 0;
}
