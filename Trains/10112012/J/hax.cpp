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

const int M = 12;
const int N = 111;

vector<int> need[M][N];
int p[M];
int n, m, k;
int w;

struct cell {
    int x, y, z;

    cell(int ax = -1, int ay = -1, int az = -1) : x(ax), y(ay), z(az) {}
};

int f[M][N][N];
cell from[M][N][N];

void relax(int nx, int ny, int nz, int nval, int fx, int fy, int fz) {
    if (f[nx][ny][nz] > nval || f[nx][ny][nz] == -1) {
        f[nx][ny][nz] = nval;
        from[nx][ny][nz] = cell(fx, fy, fz);
    }
}

bool doit(int minimum, vector<int>& resulta, vector<int>& resultb, int& maximum) {
    memset(f, -1, sizeof(f));
    f[0][n][w] = 0;

    //cerr << minimum << endl;

    for (int i = 0; i < m; ++i)
        for (int rest = 0; rest <= n; ++rest)
            for (int wa = 0; wa <= rest; ++wa) 
                if (f[i][rest][wa] != -1) {
                    //cerr << i << " " << rest << " " << wa << ": " << f[i][rest][wa] << endl;    

                    for (int add = minimum; add <= rest; ++add)
                        for (int q = 0; q < need[i][add].size(); ++q)
                            if (need[i][add][q] <= wa) {
                                relax(i + 1, rest - add, wa - need[i][add][q], max(f[i][rest][wa], add), i, rest, wa);    
                            }     
                }
    
    if (f[m][0][0] == -1) return false;

    cell cur(m, 0, 0);
    maximum = f[m][0][0];
    resulta.clear();
    resultb.clear();
    while (cur.x > 0) {
        cell prev = from[cur.x][cur.y][cur.z];
        resulta.push_back(prev.y - cur.y);
        resultb.push_back(prev.z - cur.z);
        cur = prev;
    }
    reverse(resulta.begin(), resulta.end());
    reverse(resultb.begin(), resultb.end());
    return true;
}

int main() {
    freopen("javacert.in", "r", stdin);
    freopen("javacert.out", "w", stdout);
    
    cin >> k >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> p[i];

        for (int j = 1; j <= n; ++j)
            for (int q = 0; q <= j; ++q) {
                int got = 100 * q / j;
                int md = (100 * q) % j;
                if (md > j - md) ++got;
                else if (md == j - md) {
                    if (got & 1) ++got;
                }

                if (got == p[i]) { 
                    need[i][j].push_back(j - q);
                    //cout << "done: " << i << " " << j - q << " " << j << endl;
                } 
            }
    }
    w = n - k;

    int dist = n + n;
    vector<int> a, b, ba, bb;
    for (int mn = 1; mn <= n; ++mn) {
        int mx;
        bool did = doit(mn, a, b, mx);
        if (!did) continue;

        if (mx - mn < dist) {
            ba = a;
            bb = b;
            dist = mx - mn;
        } 
    }

    for (int i = 0; i < m; ++i) {
        cout << bb[i] << " " << ba[i] << endl;
    }


    return 0;
}
