#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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
#include <cassert>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char s[22][22];
char ss[6][22];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int GetMask(char ch) {
    switch (ch) {
        case '+': return GetMask('|') | GetMask('-');
        case '-': return GetMask('<') | GetMask('>');
        case '|': return GetMask('^') | GetMask('v');
        case '>': return 1 << RIGHT;
        case '<': return 1 << LEFT;
        case '^': return 1 << UP;
        case 'v': return 1 << DOWN;
        case '.': return 0;
        default: throw 1;
    }
}

#define STOP   0
#define SFWD   1
#define SBACK  3
#define SRIGHT 4 
#define SLEFT  2
#define SBOT   5

int Top[24];
int Move[24][4];

inline void RotUp(vector<int>& v) {
    int x = v[STOP];
    v[STOP] = v[SBACK];
    v[SBACK] = v[SBOT];
    v[SBOT] = v[SFWD];
    v[SFWD] = x;
} 

inline void RotRight(vector<int>& v) {
    int x = v[STOP];
    v[STOP] = v[SLEFT];
    v[SLEFT] = v[SBOT];
    v[SBOT] = v[SRIGHT];
    v[SRIGHT] = x;
} 

inline void GenCubes() {
    int counter = 0;
    map< vector<int>, int> poss;
    vector<int> cube(6);
    for (int i = 0; i < 6; ++i) cube[i] = i;
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int& c = poss[cube];
                if (!c) c = ++counter;
                RotRight(cube);
            }
            RotUp(cube);
        }
        RotUp(cube);
        RotRight(cube);
    }
    assert(counter == 24);
    for (map< vector<int>, int>::iterator i = poss.begin(); i != poss.end(); ++i) {
        int j = i->second - 1;
        const vector<int>& cube = i->first;
        vector<int> v;
                 
        v = cube; RotRight(v);
        Move[j][RIGHT] = poss[v] - 1;
        RotRight(v); RotRight(v);
        Move[j][LEFT] = poss[v] - 1;

        v = cube; RotUp(v);
        Move[j][UP] = poss[v] - 1;
        RotUp(v); RotUp(v);
        Move[j][DOWN] = poss[v] - 1;

        Top[j] = cube[STOP];
    }
}

#define V 222222
int n, m;
int vCounter;
vector< pair<char, int> > g[V];
vector<int> bg[V];
vector<bool> good, endv;
vector< pair<int, char> > p;

void Edge(int x, int y, char ch) {
    //cerr << x << " " << y << " " << ch << endl;
    g[x].push_back(make_pair(ch, y));
    bg[y].push_back(x);
}

void AddEdge(int p, int x, int y, int pp, int xx, int yy) {
    int sv = (x * m + y) * 24 + p;
    int fv = (xx * m + yy) * 24 + pp;

    const char* s = ss[ Top[p] ];
    int i = 0;
    for (;s[i + 1] ; ++i) {
        Edge(sv, vCounter, s[i]);
        sv = vCounter;
		++vCounter;
    }
    Edge(sv, fv, s[i]);
}

char ans[12 * 12 * 12];
int an = 0;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    GenCubes();

    scanf("%d%d\n", &n, &m);
    vCounter = (n * m + 1) * 24;
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
    }
    for (int i = 0; i < 6; ++i) gets(ss[i]);
    int sx, sy, fx, fy;
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    --sx; --sy; --fx; --fy;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int msk = GetMask(s[i][j]);
            for (int k = 0; k < 4; ++k)
                if (msk & (1 << k)) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                    for (int pos = 0; pos < 24; ++pos)
                        AddEdge(pos, i, j, Move[pos][k], xx, yy);
                }
        }
    }
    for (int pos = 0; pos < 24; ++pos)
		AddEdge(pos, fx, fy, pos, n, 0); 

    assert(vCounter < V);

    for (int i = 0; i < vCounter; ++i) sort(g[i].begin(), g[i].end());

    int gc = 0;
    queue<int> q;
    good.resize(vCounter);
	endv.resize(vCounter);
	p.resize(vCounter);
    for (int i = 0; i < 24; ++i) {
        int x = n * m * 24 + i;
        good[x] = true;
		endv[x] = true;
        ++gc;
        q.push(x);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (size_t i = 0; i < bg[x].size(); ++i) {
            if (!good[bg[x][i]]) {
                good[bg[x][i]] = true;
                ++gc;
                q.push(bg[x][i]);
            }
        }
    }
    for (int i = 0; i < vCounter; ++i) {    
        for (size_t j = 0; j < g[i].size(); ) {
            if (!good[ g[i][j].second ]) {
                g[i].erase( g[i].begin() + j );
            } else ++j;
        }                    
    }

    int MaxIter = n * m * 11, iter = 0;
    int S = (sx * m + sy) * 24;

    if (!good[S]) {
        puts("no");
        return 0;
    }

    vector<int> front(1, S);
    int finita = 0;
    while (++iter <= MaxIter && !finita) {
        vector<int> back;
        back.swap(front);

        char ch = 127;
        for (size_t i = 0; i < back.size(); ++i)
            ch = min(ch, g[back[i]][0].first);

        for (size_t i = 0; i < back.size(); ++i) {
            int x = back[i];
            for (size_t j = 0; j < g[x].size(); ++j) if (g[x][j].first == ch) {
                front.push_back(g[x][j].second);
				if (!p[ g[x][j].second ].second)
					p[ g[x][j].second ] = make_pair(x, ch);
                if (endv[g[x][j].second]) {
					finita = g[x][j].second + 1;
                    break;
                }
            }
        }
        if (finita) break;
        sort(front.begin(), front.end());
        front.erase(unique(front.begin(), front.end()), front.end());
    }
    if (finita) {
		int x = finita - 1;
		while (x != S) {
			ans[an++] = p[x].second;
			x = p[x].first;
		}
		while (an) putchar(ans[--an]);
		puts("");
    } else {
        puts("infinite");
        return 0;
    }
    
    return 0;
}
