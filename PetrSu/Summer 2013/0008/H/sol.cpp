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

int n;
int rem[222];
int z[222], o[222];
vector<int> all[111][111];
int p[222], pc[222];
char ans[666];
int an = 0, MAXL = 600;

int main() {
	freopen("huffman.in",  "r", stdin);
	freopen("huffman.out", "w", stdout);

	while (true) {
		scanf("%d", &n);
		if (n == 0) break;

		priority_queue< pair<pair<int, int>, int> > q;

		memset(all, 0, sizeof(all));
		memset(rem, 0, sizeof(rem));
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &z[i], &o[i]);
			all[ z[i] ][ o[i] ].push_back(i);
			q.push( make_pair(make_pair(z[i] + o[i], o[i]), i) );
		}
		int counter = n;
		bool bad = false;
		while (q.size() > 1) {
			int ch = q.top().second; q.pop();
			if (rem[ch]) continue;

			vector<int>& a1 = all[ z[ch] ] [ o[ch] ];
			vector<int>& a2 = all[ z[ch] + 1 ] [ o[ch] - 1 ];

			if (a2.size() == 0) {
				bad = true;
				break;
			}
			int bro = a2.back();

			rem[ch] = true;
			rem[bro] = true;
			
			a1.erase(find(a1.begin(), a1.end(), ch));
			a2.erase(a2.end() - 1);

			p[ch] = p[bro] = counter;
			pc[ch] = '1';
			pc[bro] = '0';

			z[counter] = z[ch];
			o[counter] = o[ch] - 1;
			all[z[counter]][o[counter]].push_back(counter);
			q.push(make_pair(make_pair(z[counter] + o[counter], o[counter]), counter));
			++counter;
		}		
		if (!bad && q.size() == 1 && z[q.top().second] == 0 && o[q.top().second] == 0) {
			puts("Yes");
			p[q.top().second] = -1;
			for (int i = 0; i < n; ++i) {
				int x = i;
				an = MAXL;
				ans[MAXL] = 0;
				while (p[x] != -1) {
					ans[--an] = pc[x];
					x = p[x];
				}
				puts(ans + an);
			}

		} else {
			puts("No");
		}
	}
	
	return 0;
}
