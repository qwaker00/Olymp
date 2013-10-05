#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <memory.h>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <string.h>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

const int N = 500011;
char w[N];

int maxx[N], maxy[N], minx[N], miny[N];

void setx(int x, int y) {
	miny[x] = min(miny[x], y);
	maxy[x] = max(maxy[x], y);
}

void sety(int x, int y) {
	minx[y] = min(minx[y], x);
	maxx[y] = max(maxx[y], x);	
}

inline bool check(int x, int y) {
	return minx[y] <= x && x < maxx[y] && miny[x] <= y && y < maxy[x];
}

int main() {
	//freopen("in", "r", stdin);

	int T; scanf("%d\n", &T);

	while (T--) {

	gets(w);
	int l = strlen(w);

	memset(maxx, 128 + 63, sizeof(maxx));
	memset(maxy, 128 + 63, sizeof(maxx));
	memset(minx, 63, sizeof(maxx));
	memset(miny, 63, sizeof(maxx));

	int cx = 200000, cy = 200000;
	for (int i = 0; i < l; ++i) {
		if (w[i] == 'R') {
        	setx(cx, cy);		
        	++cx;
		} else if (w[i] == 'L') {
			setx(cx - 1, cy);
			--cx;
		} else if (w[i] == 'D') {
			sety(cx, cy - 1);
			--cy;
		} else if (w[i] == 'U') {
			sety(cx, cy);
			++cy;
		}		
	}

	bool cool = true;
	cx = 200000; cy = 200000;
	for (int i = 0; i < l; ++i) {
		if (w[i] == 'R') {
        	if (check(cx, cy - 1) && check(cx, cy)) {
        		cool = false;
        		break;
        	}		
        	++cx;
		} else if (w[i] == 'L') {
			if (check(cx - 1, cy - 1) && check(cx - 1, cy)) {
        		cool = false;
        		break;
        	}
			--cx;
		} else if (w[i] == 'D') {
			if (check(cx, cy - 1) && check(cx - 1, cy - 1)) {
        		cool = false;
        		break;
        	}
			--cy;
		} else if (w[i] == 'U') {
			if (check(cx, cy) && check(cx - 1, cy)) {
        		cool = false;
        		break;
        	}
			++cy;
		}
	}
	
	if (cool) puts("1");
	else puts("2");

	}

	return 0;
}
