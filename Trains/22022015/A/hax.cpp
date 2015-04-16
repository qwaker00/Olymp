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

char c[3];
string n[3];
map<string, int> num;

int type(string s) {
	if (s[0] == '.') return 0;
	if (s[0] == 'I' || s[0] == 'V') return 1;
	return 2;
}

bool isToch(string s) {
	return type(s) == 0;
}
bool isRome(string s) {
	return type(s) == 1;
}
bool isArab(string s) {
	return type(s) == 2;
}

int getNum(string s) {
	return num[s];
}
bool isPrime(int x) {
	if (x == 1) return 0;
	for (int j = 2; j < x; ++j) if ((x % j) == 0) return false;
	return true;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    num["."] = 1;
    num[".."] = 2;
    num["..."] = 3;
    num["...."] = 4;
    num["....."] = 5;
    num["......"] = 6;
    num["I"] = 1;
    num["II"] = 2;
    num["III"] = 3;
    num["IV"] = 4;
    num["V"] = 5;
    num["VI"] = 6;
    num["1"] = 1;
    num["2"] = 2;
    num["3"] = 3;
    num["4"] = 4;
    num["5"] = 5;
    num["6"] = 6;
    
    bool is1 = true;
    bool is2 = true;
    bool is3 = true;
    bool is4 = true;
    bool is5 = true;
    bool is6 = true;

    bool is8 = true;

    bool is10 = true;

	for (int i = 0; i < 3; ++i) {
		cin >> c[i] >> n[i];

//		cerr << c[i] << " " << type(n[i]) << " " << getNum(n[i]) << endl;

		if (!isToch(n[i])) is1 = false;
		if (isRome(n[i])) is2 = false;
		if (c[i] != 'W') is3 = false;
		if (c[i] != 'W' && c[i] != 'B') is4 = false;
		if (getNum(n[i]) % 2 == 0) {
			if (c[i] != 'B') is5 = false;
		} else {
			if (c[i] != 'W') is5 = false;
		}

		if (isPrime(getNum(n[i]))) {
			if (!isArab(n[i])) is6 = false;
		}
		if (isArab(n[i])) {
			if (!isPrime(getNum(n[i]))) is6 = false;
		}

		if (isRome(n[i]) && c[i] != 'Y') is8 = false;

		for (int j = 0; j < i; ++j) {
			if (type(n[i]) == type(n[j]) && c[i] != c[j])
				is10 = false;
			if (type(n[i]) != type(n[j]) && c[i] == c[j])
				is10 = false;
		}
	}

	if (is1) cout << "John ";
	if (is2) cout << "David ";
	if (is3) cout << "Peter ";
	if (is4) cout << "Robert ";
	if (is5) cout << "Mark ";
	if (is6) cout << "Paul ";
	if (c[0] == c[1] && c[1] == c[2] && c[0] != 'W' && c[1] != 'B') cout << "Patrick ";
	if (is8) cout << "Jack ";
	if (c[0] != c[1] && c[1] != c[2] && c[2] != c[0]) cout << "Max ";
	if (is10) cout << "Alex ";

    return 0;
}
