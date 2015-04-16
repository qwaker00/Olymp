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


struct TGame {
	double x, y;
	double dir;
	vector<int> dies;

	double rad(double x) {
		return x * PI / 180;
	}

	void putDies(vector<int>& v) {
		dies = v;

		#ifdef DEBUG
		cerr << "-> ";
		for (int i = 0; i < 6; ++i)
			cerr << v[i] << " ";
		cerr << "\n-> ";
		for (int i = 0; i < 6; ++i)
			cerr << v[i+6] << " ";
		cerr << endl;				
		#endif
	}

	void getInit(double& x, double& y, double& dx, double& dy) {
		x = this->x;
		y = this->y;
		dx = cos(rad(dir)) * 10;
		dy = sin(rad(dir)) * 10;
		#ifdef DEBUG
		cerr << "<- " << x << " " << y << endl;
		cerr << "<- " << dx << " " << dy << endl;
		#endif
	}

	void putTurn(int id, int& deg, bool& finish) {

		int d = (rand() % 6) + (id - 1) * 6;
		deg = dies[d];

		dir += deg;
		x += cos(rad(dir)) * 10;
		y += sin(rad(dir)) * 10;

		finish = (x * x + y * y <= 1);

		#ifdef DEBUG
		cerr << "-> " << id << endl;
		cerr << "<- " << deg << "  (" << dir << ")" << endl;
		cerr << "<- " << (finish ? "Yes" : "No") << endl;
		#endif
	}
};

unsigned rand32() {
	return (rand() << 15) + rand();
}


int play(TGame& g) {
	int turn = 0;

	double x, y;
	double dx, dy;
   	g.getInit(x, y, dx, dy);

//   	int base = (atan2(dy, dx) * 180 / PI);
//   	vector<int> dies = {60, 61, 62, 63, 58, 59, base, base + 1, base + 2, base - 1, base - 2, base - 3};
// 25, 3
	int p = 35;
	int d = 10;

	int p2 = 35;
	int d2 = 10;
   	vector<int> dies = {-p, -p-d, -p-2*d, -p-3*d, -p-4*d, -p-5*d, 
   	                     p2, p2+d2,  p2+2*d2,  p2+3*d2,  p2+4*d2,  p2+5*d2};

	g.putDies(dies);
	while (1) {
		++turn;
		#ifdef DEBUG
		cerr << "Turn #" << turn << "\n";
		#endif
		if (turn > 7500) return -1;

		int deg;
		bool finish;

		int id;
		if (x * dy > y * dx)
			id = 2;
		else
			id = 1;

		g.putTurn(id, deg, finish);
		if (finish) break;

	   	g.getInit(x, y, dx, dy);
	}

	return turn;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    srand(0);
    double st = 0;
    int mx = 0;
    int fails = 0;
    for (int it = 0; it < 100000; ++it) {
	    TGame g;
    	g.x = (rand32() % 499000000) / 1000000.0 + 2;
    	g.y = (rand32() % 499000000) / 1000000.0 + 2;
    	if (rand() & 1) g.x = -g.x;
    	if (rand() & 1) g.y = -g.y;
    	g.dir = (rand32() % 360000000) / 1000000.0;

    	double x = g.x, y = g.y, dir = g.dir;

    	int t = play(g);
    	//assert(t != -1);
    	st += t;
    	mx = max(mx, t);
//    	cerr << t << " " << st / (it + 1) << " " << mx << endl;
    	if (t == -1) {
    		++fails;
    		cerr << "fail\n";
    	}
	}
	cerr << fails << " " << st / 100000 << " " << mx << endl;
    
    return 0;
}
