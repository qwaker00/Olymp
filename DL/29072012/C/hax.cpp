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

int a, b, c, d, v, A, B, g;

int main() {
    freopen("equation.in", "r", stdin);
    freopen("equation.out", "w", stdout);

    cin >> a >> b >> c >> d >> v;
    A = a - v * c;
    B = v * d - b;

    if (c == 0 && d == 0 || a == 0 && b == 0 && v != 0) {
    	cout << "NONE\n";
    }else
    if (A == 0 && B == 0) {
    	cout << "MULTIPLE\n";
    } else
    if (A == 0 && B != 0) {
    	cout << "NONE\n";
    } else {
    	if (B * c == - d * A) {
    		cout << "NONE\n";
    		return 0;
    	}
    	if (A < 0) {
    		B *= -1;
    		A *= -1;
    	} else if (B == 0) A = 1;
    	g = __gcd(abs(B), abs(A));
    	cout << "X = " << (B/g) << "/" << (A/g) << endl;
    }


    return 0;
}
