#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

vector< pair<string, int> > atomics;

const int M = 22;

char w[22][22];
int n, m;
string result[4444];

bool used[M][M][M];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
	atomics.push_back(make_pair("I",1));
	atomics.push_back(make_pair("XL",40));
	atomics.push_back(make_pair("D",500));
	atomics.push_back(make_pair("IV",4));
	atomics.push_back(make_pair("L",50));
	atomics.push_back(make_pair("CM",900));
	atomics.push_back(make_pair("V",5));
	atomics.push_back(make_pair("XC",90));
	atomics.push_back(make_pair("M",1000));
	atomics.push_back(make_pair("IX",9));
	atomics.push_back(make_pair("C",100));
	atomics.push_back(make_pair("X",10));
	atomics.push_back(make_pair("CD",400));
	for (int i = 0; i < atomics.size(); ++i)
		for (int j = i + 1; j < atomics.size(); ++j)
			if (atomics[i].second > atomics[j].second) {
				swap(atomics[i], atomics[j]);
			}

	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		gets(w[i]);
	}

	for (int val = 1; val < 4000; ++val) {
		int who = atomics.size() - 1;

		while (atomics[who].second > val) --who;
		result[val] = atomics[who].first + result[val - atomics[who].second];

		string s = result[val];

		queue< pair<pair<int, int>, int> > q;

		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; ++i)
			if (w[i][0] == s[0]) {
				q.push(make_pair(make_pair(i, 0), 0));
				used[i][0][0] = true;
			}

		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int pos = q.front().second;
			q.pop();
			if (pos + 1 == s.size()) continue;
			
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m || w[nx][ny] != s[pos + 1] || used[nx][ny][pos + 1]) continue;
				used[nx][ny][pos + 1] = true;
				q.push(make_pair(make_pair(nx, ny), pos + 1));
			}
		}

		for (int i = 0; i < n; ++i)
			if (used[i][m - 1][s.size() - 1]) {
				cout << s << endl;
				return 0;
			}
	}

	puts("NO");
	    
    return 0;
}
