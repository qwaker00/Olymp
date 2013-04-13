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

char s[222222], lex[222222];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
	gets(s);
	int l = strlen(s), ln;
	s[l++] = ' ';

	int state = 0;
	for (int i = 0; i < l; ++i) {
		if (state == 0) {
			if (s[i] == ' ') continue;
			if (s[i] == '"') {
				state = 1;
				ln = 0;
				continue;
			}
			ln = 0;
			lex[ln++] = s[i];
			state = 2;
			continue;
		} else		
		if (state == 1) {
			if (s[i] == '"') {
				lex[ln] = 0;
				printf("<%s>\n", lex);
				ln = 0;

				state = 0;
				continue;
			}
			lex[ln++] = s[i];
			continue;
		} else
		if (state == 2) {
			if (s[i] == ' ') {
				lex[ln] = 0;
				printf("<%s>\n", lex);
				ln = 0;

				state = 0;
				continue;
			}
			if (s[i] == '"') {
				throw 1;
			}
			lex[ln++] = s[i];
			continue;
		}
	}
    
    return 0;
}
