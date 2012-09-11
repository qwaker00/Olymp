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

char word[2222];
int n;

pair<LL, LL> words[2222];
LL p29[2222], p31[2222], st1[2222], st2[2222], fin1[2222], fin2[2222];
char s[2222][2222];
int h, w, stdot[2222], findot[2222];

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);

	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		gets(word);

		LL h1 = 0, h2 = 0;
		for (int j = 0; word[j]; j++) {
			h1 = h1 * 29 + word[j] - 'a' + 1;
			h2 = (h2 * 31 + word[j] - 'a' + 1) % 1000000007;
		}
		words[i] = make_pair(h1, h2);
	}
	sort(words, words + n);

	p29[0] = 1;
	p31[0] = 1;
	for (int i = 1; i <= 2000; i++) {
		p29[i] = p29[i - 1] * 29;
		p31[i] = (p31[i - 1] * 31) % 1000000007;
	}

	scanf("%d\n", &h);
	for (int i = 0; i < h; i++) {
		gets(s[i]);
		w = strlen(s[0]);

		char * ss = s[i];

		if (ss[0] == '.') stdot[i] = true; else {
			st1[i] = st2[i] = 0;
			for (int j = 0; ss[j] != '.'; j++) {
				st1[i] = st1[i] * 29 + ss[j] - 'a' + 1;
				st2[i] = (st2[i] * 31 + ss[j] - 'a' + 1)  % 1000000007;
			}
		}

		if (ss[w - 1] == '.') findot[i] = true; else {
			fin1[i] = fin2[i] = 0;
			for (int j = w - 1, p = 0; ss[j] != '.'; j--, p++) {
				fin1[i] += (ss[j] - 'a' + 1) * p29[p];
				fin2[i] = (fin2[i] + (ss[j] - 'a' + 1) * p31[p]) % 1000000007;
			}
		}
	}

	for (int dw = 0; dw < w; dw++) {
		if ( !Good(st1[0], st2[0]) ) continue;

		bool good = true;
		for (int i = 1; i < h; i++) {
			LL h1 = fin1[i - 1] * p29[]
		}
	}

	return 0;
}
