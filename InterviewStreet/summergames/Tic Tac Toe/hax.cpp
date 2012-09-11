#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <sstream>
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

int field[3][3], myId, px[9] = {2, 0, 0, 2, 2, 0, 1, 1, 1}, py[9] = {2, 0, 2, 0, 1, 1, 0, 2, 1};

bool Check(int id) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (field[i][j] != id) break;
			if (j == 2) return true;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (field[j][i] != id) break;
			if (j == 2) return true;
		}
	}

	if (field[0][0] == id && field[1][1] == id && field[2][2] == id)
		return true;

	if (field[2][0] == id && field[1][1] == id && field[0][2] == id)
		return true;

	return false;
}

int Win(int id) {
	if (Check(id)) return 1;
	if (Check(3 - id)) return -1;

	int maxWin = -1, fr = 0;
	for (int i = 0; i < 9; ++i) {	
		if (field[px[i]][py[i]] != -1) continue;
		++fr;
		field[px[i]][py[i]] = 3 - id;
		maxWin = max(maxWin, Win(3 - id));
		field[px[i]][py[i]] = -1;
	}

	if (fr == 0) return 0;
	return -maxWin;
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> myId;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> field[i][j];
		}
	}

	for (int i = 0; i < 9; ++i) {
		if (px[i] < 0 || py[i] < 0 || px[i] > 2 || py[i] > 2) throw 1;
		for (int j = i + 1; j < 9; ++j) {
			if (px[i] == px[j] && py[i] == py[j]) {
				throw 2;
			}
		}
	}

	for (int it = 1; ; --it)
		for (int i = 0; i < 9; ++i) {
			if (field[px[i]][py[i]] != -1) continue;
			field[px[i]][py[i]] = myId;
			if (Win(myId) == it) {
				cout << px[i] << " " << py[i] << endl;
				return 0;
			}
			field[px[i]][py[i]] = -1;
		}
	throw 3;

	return 0;
}
