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

const int N = 200022;

deque<int> g[N];
map<int, int> q;
int kv = 0;

char geto() {
	char c = getchar();
	while (c != 'A' && c != 'M' && c != 'E') c = getchar();
	return c;
}

inline int getnum(int id) {
	map<int, int>::iterator it = q.find(id);
	if (it == q.end()) {
		q[id] = kv++;
		return kv - 1;
	} 
	return it->second;
}

void print() {
    for (map<int, int>::iterator it = q.begin(); it != q.end(); ++it)
		if (g[it->second].size() > 0) {
			printf("%d:", it->first);
			int num = it->second;
			for (deque<int>::reverse_iterator it2 = g[num].rbegin(); it2 != g[num].rend(); ++it2) {
				printf(" %d", *it2);
			}
			printf("\n");
		}
}

int main() {
	while (true) {
		char c = geto();
		if (c == 'E') {
			break;
		}

		if (c == 'A') {
			int b, f;
			scanf("%d%d", &b, &f);
			b = getnum(b);
			g[b].push_back(f);			
		} else {
        	int a1, a2;
        	scanf("%d%d", &a1, &a2);

			// a1 --> a2
			int id1 = getnum(a1), id2 = getnum(a2);
			if (g[id1].size() <= g[id2].size()) {
				for (deque<int>::iterator it = g[id1].begin(); it != g[id1].end(); ++it) {
					g[id2].push_back(*it);
				}
				g[id1].clear();
			} else {
				for (deque<int>::reverse_iterator it = g[id2].rbegin(); it != g[id2].rend(); ++it) {
					g[id1].push_front(*it);
				}
				g[id2].clear();
				q[a1] = id2;
				q[a2] = id1;
			}
		}
	}	

	print();

	return 0;
}
