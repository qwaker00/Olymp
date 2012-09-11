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

char morze[26][11] = {
".-", "-...", "-.-.", "-..",
".", "..-.", "--." ,"....",
"..",".---","-.-",".-..",
"--","-.","---",".--.",
"--.-",".-.","...","-",
"..-","...-",".--","-..-",
"-.--","--.."};

int ll[26];
char s[111];
LL ans;
LL f[111];
bool E[111][33];

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    for (int i = 0; i < 26; i++) ll[i] = strlen(morze[i]);

	cin >> s >> ans;
	int l = strlen(s);
	f[l] = 1;
	for (int i = l - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			int eq = true;
			for (int k = 0; k < ll[j]; k++) {
				if (s[k + i] != morze[j][k]) {
					eq = false;
					break;
				}
			}
			if (eq) {
				E[i][j] = true;
				f[i] += f[i + ll[j]];
			}
		}
	}
	if (f[0] < ans) {
		cout << 0 << endl;
	} else {
		int st = 0;
		while (st < l) {
		for (int j = 0; j < 26; j++) if (E[st][j]) {
			if (f[st + ll[j]] < ans) {
				ans -= f[st + ll[j]];
			} else {
				cout << char(j + 'A');
				st += ll[j];
				break;
			}
		}
		}
		cout << endl;
	}

    return 0;
}
