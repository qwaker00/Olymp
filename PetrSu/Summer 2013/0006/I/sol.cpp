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

struct cell {  	
	int upthis_max;
	int upthis_min;

	int downthis_max;
	int downthis_min;
	
	int curmax;
	int curmin;
};

cell vert[300000];
int fath[300000];

int n  = 0;

vector<vector<int> > adjlist;

void build_tree() {
	queue<int> q;
	q.push_back(1);
	while (!q.empty()) {
		int v = q.top();
		q.pop();
		for (int i = 0; i < adjlist[v].size(); ++i) {
			int cand = adjlist[v][i];
			if (!fath[cand]) {
				fath[cand] = v;
				q.push_back(cand);
			}
		}	
	}
}

void run(int vert) {
	int prohibited = fath[vert];
	int runcnt = 0;
	for (int i = 0; i < adjlist[vert].size(); ++i) {
		int cand = adjlist[vert][i];
		if (cand != prohibited) {
			++runcnt;
			run(cand);
		}
	}
	// First case : runcnt = 0. Means we have a leaf.
	if (runcnt == 0) {
		curmax = 	
	}		
}


int main() {
	scanf("%d", &n);
	adjlist.resize(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
	build_tree();
	run(1);	
		
	return 0;
}
