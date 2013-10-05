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
#include <time.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ld PI = acos(-1.);
using namespace std;

char w[111];
char ST[111], FIN[111];
int n, k;

set<ll> bad;
ll st, fin;

inline ll getnum(char* w) {
	ll x = 0;
	for (int i = 0; i < n; ++i)
		if (w[i] == '1')
			x += (1LL << i);
	return x;
}


int main() {
	//freopen("in", "r", stdin);

	scanf("%d%d", &n, &k);
	scanf("%s %s\n", ST, FIN);
	st = getnum(ST);
	fin = getnum(FIN);
	

	for (int i = 0; i < k; ++i) {
		gets(w);
		ll x = 0;
        for (int i = 0; i < n; ++i) 
        	if (w[i] == '1') x += (1LL << i);
		bad.insert(x);
	}

	if (st == fin) {
		puts("TAK");
		return 0;
	}

    int lim = 3000000;

    queue<ll> q;
	q.push(st);
	set<ll> was;
	was.insert(st);

	while (!q.empty() && was.size() <= lim) {
		ll x = q.front(); q.pop();

		for (int i = 0; i < n; ++i) {
			ll y = x ^ (1LL << i);
			if (y == fin) {
				puts("TAK");
				return 0;
			}

			if (bad.find(y) == bad.end()) {
				if (was.find(y) == was.end()) {
					was.insert(y);
					q.push(y);
				}
			}
		}
	}

	if (q.empty()) {
		puts("NIE");
		return 0;
	}	

	queue<ll> q2;
	q2.push(fin);
	set<ll> was2;
	was2.insert(fin);

	while (!q2.empty() && was2.size() <= lim) {
		ll x = q2.front(); q2.pop();

		for (int i = 0; i < n; ++i) {
			ll y = x ^ (1LL << i);
			if (was.find(y) != was.end()) {
				puts("TAK");
				return 0;
			}

			if (bad.find(y) == bad.end()) {
				if (was2.find(y) == was2.end()) {
					was2.insert(y);
					q2.push(y);
				}
			}
		}
	}

	if (q2.empty()) {
		puts("NIE");
		return 0;
	}

	//cerr << clock() << endl;
	puts("TAK");
		

	return 0;
}
