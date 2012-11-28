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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int M = 16;
const int N = 1 << M;

char mp[N][M][M];
int n, m, k;

char w[M][M], who[M][M];
int d[N][M][M];

struct cell {
    int x, y, kind;
} a[M];
int sx, sy;

bool good(int y, int z) {
    if (y < 0 || y >= n || z < 0 || z >= m) return false;
    return true;
}

void mark(int x, int y, int z)  {
    if (!good(y, z)) return;
    ++mp[x][y][z]; 
}

int kd[8][2] = {{2, 1}, {2, -1}, {1, -2}, {1, 2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};

struct node {
    int x, y, msk;

    node(int ax, int ay, int amsk) : x(ax), y(ay), msk(amsk) {}

    node() {x = y = msk = 0;}

    bool operator <(const node& A) const {
        if (x != A.x) return x < A.x;
        if (y != A.y) return y < A.y;
        return msk < A.msk;
    }
};

queue<node> q;

//map<node, node> fath;


void relax(node t, int nv, node f = node(-1,0,0)) {
    if (!good(t.x, t.y)) return;
    if (d[t.msk][t.x][t.y] > nv) {
        d[t.msk][t.x][t.y] = nv;
        q.push(t);

        //fath[t] = f;
    }
}                

bool should(int msk, int x, int y) {
    if (!good(x, y)) return true;
    if (who[x][y] == -1) return false;
    return (msk & (1 << int(who[x][y])));
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n >> m;
    cin.ignore();

    memset(who, -1, sizeof(who));
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        for (int j = 0; j < m; ++j) {
            if (w[i][j] == '*') {
                sx = i; sy = j;
                continue;
            }     

            if (w[i][j] == 'K') {
                a[k].x = i;
                a[k].y = j;
                a[k].kind = 0;

                who[i][j] = k++;
                continue;
            }

            if (w[i][j] == 'B') {
                a[k].x = i;
                a[k].y = j;
                a[k].kind = 1;
                
                who[i][j] = k++;
                continue;
            }


            if (w[i][j] == 'R') {
                a[k].x = i;
                a[k].y = j;
                a[k].kind = 2;
                
                who[i][j] = k++;
                continue;
            }
        }
    }

    int lim = 1 << k;
    for (int msk = 0; msk < lim; ++msk) {
        for (int i = 0; i < k; ++i) 
        if (msk & (1 << i)){
           int x = a[i].x, y = a[i].y;

           if (a[i].kind == 0) {
                for (int mv = 0; mv < 8; ++mv)
                    mark(msk, x + kd[mv][0], y + kd[mv][1]);
           } else if (a[i].kind == 2) {
                for (int dx = 1; ; ++dx) {
                    mark(msk, x + dx, y);
                    if (should(msk, x + dx, y)) break;
                }
                for (int dx = -1; ; --dx) {
                    mark(msk, x + dx, y);
                    if (should(msk, x + dx, y)) break;
                }

                for (int dx = 1; ; ++dx) {
                    mark(msk, x, y + dx);
                    if (should(msk, x, y + dx)) break;
                }
                for (int dx = -1; ; --dx) {
                    mark(msk, x, y + dx);
                    if (should(msk, x, y + dx)) break;
                }
           } else {
                for (int i = 1; ; ++i) {
                    int nx = x + i;
                    int ny = y + i;      
                    mark(msk, nx, ny);
                    if (should(msk, nx, ny)) break;
                }

                for (int i = 1; ; ++i) {
                    int nx = x + i;
                    int ny = y - i;      
                    mark(msk, nx, ny);
                    if (should(msk, nx, ny)) break;
                }

                for (int i = 1; ; ++i) {
                    int nx = x - i;
                    int ny = y + i;      
                    mark(msk, nx, ny);
                    if (should(msk, nx, ny)) break;
                }

                for (int i = 1; ; ++i) {
                    int nx = x - i;
                    int ny = y - i;      
                    mark(msk, nx, ny);
                    if (should(msk, nx, ny)) break;
                }
           }
        }

        //cerr << "msk = " << msk << endl;
        //for (int i = 0; i < n; ++i) {
          //  for (int j = 0; j < m; ++j)  
            //    cerr << int(mp[msk][i][j]);
            //cerr << endl;
        //}
    }

    memset(d, 63, sizeof(d));
    d[lim - 1][sx][sy] = 0;

    
    q.push(node(sx, sy, lim - 1));
    while (!q.empty()) {
        node T = q.front(); q.pop();
        //cerr << T.msk << ": " << T.x << " " << T.y << " with " << d[T.msk][T.x][T.y] << endl; 
        if (T.msk == 0) {
            cout << d[T.msk][T.x][T.y] << endl;
            return 0;
        }

        int msk = T.msk;
        int x = T.x;
        int y = T.y;

        int nv = d[T.msk][T.x][T.y] + 1;
        for (int dx = -1; dx <= 1; ++dx)
            for (int dy = -1; dy <= 1; ++dy) { 
                int nx = x + dx, ny = y + dy;
                int nmsk = msk;

                if (!mp[msk][nx][ny]) {
                    if (who[nx][ny] != -1) { 
                        if (nmsk & (1 << int(who[nx][ny]))) 
                            nmsk ^= (1 << int(who[nx][ny]));
                            
                    }    
                    relax(node(nx, ny, nmsk), nv, T);
                }
            }
    }

    cout << "-1" << endl;
    
    return 0;
}
