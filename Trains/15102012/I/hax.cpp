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

int d[55][55];
int f[263333][19];
pair<int,int> p[263333][19], best[263333];
int nn, ans1, ans2;
queue< pair<int,int> > q;
int n, m, x, y, v[263333];

void rec(pair<int,int>& b, vector<int>& v) {
    if (b.first > 1) rec(p[b.first][b.second], v);
    v.push_back(b.second);
}

int main() {
    freopen("immediate.in", "r", stdin);
    freopen("immediate.out", "w", stdout);

    memset(d, 63, sizeof(d));
    cin >> n >> m;
    for (int i =0 ; i < m; i++) {
        int c;
        cin >> x >> y >> c;
        x--;
        y--;
        d[x][y] = d[y][x] = min(d[x][y], c);
    }
    memset(f, 63, sizeof(f));

    f[1][0] = 0;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        pair<int,int> t = q.front(); q.pop();
        int dd = f[t.first][t.second];
        //cerr << t.first << " " << t.second << " " << dd << endl;
        for (int j = 0; j < n; j++) {
            int msk = t.first | (1 << j);

            if (f[msk][j] > dd + d[t.second][j]) {
                f[msk][j] = dd + d[t.second][j];
                p[msk][j] = t;            
                q.push(make_pair(msk, j));
            }
        }
    }

    nn = (1 << n);
    for (int i = nn - 1; i > 0; i--) {
        int& mind = v[i] = 1e9;
        for (int j = 0; j < n; j++) if (f[i][j] < mind) {
            mind = f[i][j];
            best[i] = make_pair(i, j);
        }
        for (int j = 0; j < n; j++) if (v[i | (1 << j)] < mind) {
            mind = v[i | (1 << j)];
            best[i] = best[i | (1 << j)];
        }
    }

    int ans = 1e9;
    for (int i = 0; i < nn; i++) if(max(v[i], v[(nn - 1) ^ i]) < ans) {
        ans = max(v[i], v[(nn - 1) ^ i]);
        ans1 = i;
        ans2 = (nn - 1) ^ i;
    }
    cout << ans << endl;

    vector<int> v1, v2;
    rec(best[ans1], v1);
    rec(best[ans2], v2);

    if (!v1.size()) v1.push_back(0);
    cout << (int)v1.size() - 1;
    for (int i = 0; i < v1.size(); i++) cout << " " << (v1[i] + 1);
    cout << endl;


    if (!v2.size()) v2.push_back(0);
    cout << (int)v2.size() - 1;
    for (int i = 0; i < v2.size(); i++) cout << " " << (v2[i] + 1);
    cout << endl;

    return 0;
}
