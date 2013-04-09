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


int IT;
vector<int> was;
vector<int> yy;
vector<int> ff;
vector<int> mm;
vector<vector<int>> g;

void Add(int x, int y) {
//    cerr << x << " " << y << endl;
    yy.push_back(y);
    ff.push_back(1);
    mm.push_back(yy.size());
    g[x].push_back(yy.size() - 1);

    yy.push_back(x);
    ff.push_back(0);
    mm.push_back(yy.size() - 2);
    g[x].push_back(yy.size() - 1);
}

bool dfs(int x, int T) {
    if (x == T) return true;
    if (was[x] == IT) return false;
    was[x] = IT;
    for (size_t i = 0; i < g[x].size(); ++i) {
        if (ff[ g[x][i] ] && dfs(yy[ g[x][i] ], T)) {
            --ff[g[x][i]];
            ++ff[mm[g[x][i]]];
            return true;
        }
    }
    return false;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    vector<string> board;
    board.push_back("X.....XXX.XX..XXXXXXXXX...X.XX.XX....X");
    board.push_back(".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX");
    board.push_back("....XX....X.XX..X.X...XX.X..XXXXXXX..X");
    board.push_back("XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X...");

    #define V1(x, y) ((((x)*m)+(y))*2+1)
    #define V2(x, y) ((((x)*m)+(y))*2+2)

    int n = board.size(), m = board[0].size();
    int S = 0, T = V2(n - 1, m - 1) + 1;
    g.resize(T + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'X') continue;

            if ((i + j) & 1) {
                if ( j & 1 ) {
                    Add( S , V1(i, j) );
                    Add( V1(i, j), V2(i, j) );
                    if (i > 0)
                        Add( V2(i, j) , V1(i - 1, j) );
                    if (i < n - 1)
                        Add( V2(i, j) , V1(i + 1, j) );
                    if (j > 0)
                        Add( V2(i, j) , V1(i, j - 1) );
                    if (j < m - 1)
                        Add( V2(i, j) , V1(i, j + 1) );
                } else {
                    Add( V1(i, j), V2(i, j) );                    
                    Add( V2(i, j), T );
                    if (i > 0)
                        Add( V2(i - 1, j), V1(i, j) );
                    if (i < n - 1)
                        Add( V2(i + 1, j), V1(i, j) );
                    if (j > 0)
                        Add( V2(i, j - 1), V1(i, j) );
                    if (j < m - 1)
                        Add( V2(i, j + 1), V1(i, j) );
                }

            } else {
                Add( V1(i, j) , V2(i, j) );
            }
        }
    }

    was.resize(T + 1);
    IT = 1;
    while (dfs(S, T)) {
        ++IT;
    }

    cout << IT - 1 << endl;
    
    return 0;
}
