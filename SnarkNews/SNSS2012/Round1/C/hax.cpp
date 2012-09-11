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

struct Tp{
	int x, y;
	char c;
	bool operator<(const Tp& B)const{
		return c < B.c;
	}
	bool operator==(const Tp& B)const{
		return x == B.x && y == B.y;
	}
} a[111];
int mem[13][13][13][13];
int an, sx, sy;
char f[13][13];

inline bool In(Tp& a, Tp& b, Tp& c) {
	if (a.x == b.x && a.y == b.y) return false;
	if (a.x == c.x && a.y == c.y) return false;
	return (abs(a.x - c.x) + abs(a.x - b.x) == abs(c.x - b.x)) && (abs(a.y - c.y) + abs(a.y - b.y) == abs(c.y - b.y));
}

bool Intersect(Tp& a, Tp& b, Tp& c, Tp& d) {
	int A = a.y - b.y;
	int B = b.x - a.x;
	int C = - A * a.x - B * a.y;

	int t1 = (A * c.x + B * c.y + C);
	int t2 = (A * d.x + B * d.y + C);
	if (t1 * t2 > 0) return false;

	if (t1 == 0 && t2 == 0) {
		if (In(c, a, b) || In(d, a, b)) return true;
		return (In(a, c, d) || In(b, c, d));
	}
	if (t1 == 0 || t2 == 0) {
		return In(a, c, d) || In(b, c, d) || In(c, a, b) || In(d, a, b);
	}

	A = c.y - d.y;
	B = d.x - c.x;
	C = - A * c.x - B * c.y;

	t1 = (A * a.x + B * a.y + C);
	t2 = (A * b.x + B * b.y + C);
	if (t1 * t2 > 0) return false;
	if (t1 == 0 || t2 == 0) return In(a, c, d) || In(b, c, d) || In(c, a, b) || In(d, a, b);

	return true;
}

char ans[111];
int was[11];
int bad[111][111];
int st[111];

bool Rec(int i) {
	if (i == 11) {
		cout << "[" << a[11].x << "," << a[11].y << ", 's']," << endl;
		for (int i = 0; i < 11; i++) {
			cout << "[" << a[st[i + 1]].x << "," << a[st[i + 1]].y << ", '" << a[st[i + 1]].c << "']," << endl;
			ans[i] = a[st[i + 1]].c;
		}
		return true;
	}
	for (int t = 0; t < 11; t++)
		if (!was[t] && !bad[t][st[i]]) {
			bool good = true;
			for (int j = 0; j < i; j++) if (mem[st[j]][st[j + 1]][st[i]][t]) {
				good = false;
				break;
			}
			if (good) {
				st[i + 1] = t;
				was[t] = true;
				if (Rec(i + 1)) {
					return true;
				}
				was[t] = false;
			}
		}
	return false;
}

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);

    while (1) {
    	cin >> (f[1] + 1);
    	if (strcmp(f[1] + 1, "0") == 0) break;
    	for (int i = 2; i < 8; i++) cin >> (f[i] + 1);

    	an = 0;
    	for (int i = 1; i < 8; i++)
    		for (int j = 1; j < 8; j++) {
    			if (f[i][j] == 's') {
    				sx = i;
    				sy = j;
    			} else
    			if (f[i][j] != '.') {
    				a[an].x = i;
    				a[an].y = j;
    				a[an++].c = f[i][j];
    			}
    		}
		sort(a, a + an);
		a[an].x = sx;
		a[an].y = sy;

		memset(mem, 0, sizeof(mem));
		memset(bad, 0, sizeof(bad));


		for (int i = 0; i <= an; i++)
			for (int j = 0; j <= an; j++)
				if (abs(a[i].x - a[j].x) == abs(a[i].y - a[j].y))
					bad[i][j] = bad[j][i] = true;

		for (int i = 0; i <= an; i++)
			for (int j = i + 1; j <= an; j++)
				for (int ii = 0; ii <= an; ii++) {	
					for (int jj = ii + 1; jj <= an; jj++)  if(ii != i || jj != j) {
						mem[i][j][ii][jj] = 
						mem[j][i][ii][jj] = 
						mem[i][j][jj][ii] = 
						mem[j][i][jj][ii] = Intersect(a[i], a[j], a[ii], a[jj]);
                    }
				}

		int way[] = {11, 0, 1, 5, 2, 3, 9, 6, 7, 4, 8, 10};
		for (int i = 0; i < 12; i++)
			for (int j = i + 1; j < 12; j++)
				if (mem[way[i]][way[i+1]][way[j]][way[j+1]]) {
					cerr << a[way[i]].c << " " << a[way[i+1]].c << " " << a[way[j]].c  << " " << a[way[j+1]].c << endl;
				}
	

		ans[0] = '!';
		ans[11] = 0;
		st[0] = an;
		memset(was, 0, sizeof(was));
		Rec(0);
		if (ans[0] == '!')
			cout << "impossible!\n";else
			cout << "s"<< ans << endl;
    }

    return 0;
}
