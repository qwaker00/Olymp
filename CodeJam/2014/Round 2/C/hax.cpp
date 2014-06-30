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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

struct Tp {
    int x1, y1, x2, y2;
} b[1111];
int h[4008];
int hn = 0;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, 1};
bool f[1111][4444];
int W, H;

const int VN = 111111;// * 4444 * 2;
int was[VN], IT = 0;
vector<int> g[VN];
vector<int> fl[VN];
vector<int> r[VN];

bool flow(int x) {
    if (was[x] == IT) return 0;
    if ((x & 1) && ((x / 2) / W) == hn - 1) return 1;
    was[x] = IT;

    for (int i = 0; i < (int)g[x].size(); ++i) {
        if (fl[x][i] && flow(g[x][i])) {
            fl[x][i]--;
            fl[g[x][i]][r[x][i]]++;
            return 1;
        } 
    }

    return 0;
}

void add(int x, int y, int z) {
    //cerr << ((x / 2) % W) << " " << ((x / 2) / W) << " " << (x & 1) << " -> " << ((y / 2) % W) << " " << ((y / 2) / W) << " " << (y &1) << endl;

    g[x].push_back(y);
    fl[x].push_back(z);
    r[x].push_back(g[y].size());       

    g[y].push_back(x);
    fl[y].push_back(0);
    r[y].push_back(g[x].size() - 1);       
}
           
#define HIN(x, y) ((((y)*W)+(x))*3)
#define VIN(x, y) (((((y)*W)+(x))*3)+1)
#define OUT(x, y) (((((y)*W)+(x))*3)+2)

int main() {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
    
    int T;
    int it = 0;
    cin >> T;
    while (T--) {
        ++it;

        int B;
        cin >> W >> H >> B;
        hn = 0;
        for (int i = 0; i < B; ++i) {
            cin >> b[i].x1 >> b[i].y1 >> b[i].x2 >> b[i].y2;
            h[hn++] = b[i].y1;
            h[hn++] = b[i].y2;
            if (b[i].y1 > 0)
            h[hn++] = b[i].y1 - 1;
            if (b[i].y2 < H - 1)
            h[hn++] = b[i].y2 + 1;
        }
        h[hn++] = 0;
        h[hn++] = H - 1;
        h[hn++] = 1;
        h[hn++] = H - 2;
        sort(h, h + hn);
        hn = unique(h, h + hn) - h;
        
//        hn = H;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < B; ++i) {
            b[i].y1 = lower_bound(h, h + hn, b[i].y1) - h;
            b[i].y2 = lower_bound(h, h + hn, b[i].y2) - h;
            for (int j = b[i].x1; j <= b[i].x2; ++j) {
                for (int k = b[i].y1; k <= b[i].y2; ++k) {
                    f[j][k] = 1;
                }
            }
        }

        assert(VN > OUT(W - 1, hn - 1));
        assert(VN > W * hn * 2);

        for (int i = 0; i < W; ++i)
            for (int j = 0; j < hn; ++j) {
                if (f[i][j]) continue;
                for (int k = 0; k < 2; ++k) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if (xx < 0 || yy < 0 || xx >= W || yy >= hn || f[xx][yy]) continue;
                    int z = 1;
                    if (i != xx) {
                        z = ((j == hn - 1) ? 1 : (h[j + 1] - h[j]));
                        assert(z > 0);
                        add(OUT(i, j), VIN(xx, yy), z);
                        add(OUT(xx, yy), VIN(i, j), z);
                    } else {
                        add(OUT(i, j), HIN(xx, yy), 1);
                        add(OUT(xx, yy), HIN(i, j), 1);
                    }
                }
                add(VIN(i, j), OUT(i, j), ((j == hn - 1) ? 1 : (h[j + 1] - h[j])));
                add(HIN(i, j), OUT(i, j), 1);
            }                            

        int ans = 0;
        for (int i = 0; i < W; ++i) {
            ++IT;
            if (flow(IN(i, 0))) {
                ++ans;
            }
        }

        for (int i = 0; i <= W * hn * 2; ++i) {
            g[i].clear();
            fl[i].clear();
            r[i].clear();
        }

        cout << "Case #" << it << ": " << ans << endl;
        //cerr << clock() << endl;
    }
    
    return 0;
}
