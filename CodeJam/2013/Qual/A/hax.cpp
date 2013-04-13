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

char f[5][5];


bool CheckDiag1(char p) {
	return (f[0][0] == p || f[0][0] == 'T') &&
		   (f[1][1] == p || f[1][1] == 'T') &&
		   (f[2][2] == p || f[2][2] == 'T') &&
		   (f[3][3] == p || f[3][3] == 'T');
}
bool CheckDiag2(char p) {
	return (f[0][3] == p || f[0][3] == 'T') &&
		   (f[1][2] == p || f[1][2] == 'T') &&
		   (f[2][1] == p || f[2][1] == 'T') &&
		   (f[3][0] == p || f[3][0] == 'T');
}
bool CheckRow(char p, int i) {
	return (f[i][0] == p || f[i][0] == 'T') &&
		   (f[i][1] == p || f[i][1] == 'T') &&
		   (f[i][2] == p || f[i][2] == 'T') &&
		   (f[i][3] == p || f[i][3] == 'T');
}
bool CheckCol(char p, int i) {
	return (f[0][i] == p || f[0][i] == 'T') &&
		   (f[1][i] == p || f[1][i] == 'T') &&
		   (f[2][i] == p || f[2][i] == 'T') &&
		   (f[3][i] == p || f[3][i] == 'T');
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    int T;
	cin >> T;
	for (int __it = 1; __it <= T; ++__it) {

		for (int i = 0; i < 4; ++i)	{
			scanf("%s", f[i]);
		}

		bool xWon = false, oWon = false, all = true;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (f[i][j] == '.') all = false;
			}
		}

		xWon |= CheckDiag1('X');
		oWon |= CheckDiag1('O');
		xWon |= CheckDiag2('X');
		oWon |= CheckDiag2('O');
		for (int i = 0; i < 4; ++i) {
			xWon |= CheckRow('X', i) | CheckCol('X', i);
			oWon |= CheckRow('O', i) | CheckCol('O', i);
		}

		if (xWon && oWon) {
			for (int i = 0; i < 4; ++i) cerr << f[i] << endl;
		}

		printf("Case #%d: ", __it);
		if (xWon && !oWon) puts("X won");else
		if (!xWon && oWon) puts("O won");else
		if (all || (xWon && oWon)) puts("Draw");else
			puts("Game has not completed");
	}    
    
    return 0;
}
