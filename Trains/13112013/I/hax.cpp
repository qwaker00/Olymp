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

int mark[22][22];
char s[22][22];
int was[22][22];
int IT = 0, n;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int tryfill(int ch) {
    ++IT;
    queue< pair<int, int> > q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (mark[i][j]) {
                q.push(make_pair(i, j));
                was[i][j] = IT;
            }
    int cnt = 0;
    while (!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        ++cnt;
        for (int i = 0; i < 4; ++i) {
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= n || s[xx][yy] != ch || was[xx][yy] == IT) continue;
            q.push(make_pair(xx, yy));
            was[xx][yy] = IT;
        }
    }
    return cnt;
}

void makefill(int ch) {
    ++IT;
    queue< pair<int, int> > q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (mark[i][j]) {
                q.push(make_pair(i, j));
                s[i][j] = ch;
                was[i][j] = IT;
            }
    while (!q.empty()) {
        pair<int, int> t = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= n || s[xx][yy] != ch || was[xx][yy] == IT) continue;
            q.push(make_pair(xx, yy));
            was[xx][yy] = IT;
            mark[xx][yy] = 1;
        }
    }
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int T;
    scanf("%d\n", &T);
    while (T--) {
        memset(mark, 0, sizeof(mark));

        int cnt = 1;
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i) gets(s[i]);
        mark[0][0] = 1;

        int ans[6], moves = 0;
        memset(ans, 0, sizeof(ans));

        cnt = tryfill(s[0][0]);
        makefill(s[0][0]);
        while (cnt != n * n) {
            int maxt = -1;
            int mi = 0;
            for (int c = '1'; c <= '6'; ++c) {
                int t = tryfill(c);
                if (t > maxt) {
                    maxt = t;
                    mi = c;
                }
            }
            makefill(mi);
            cnt = maxt;
            ++moves;
            ++ans[mi - '1'];
        }
        printf("%d\n", moves);
        for (int i=  0; i < 6; ++i)
            printf("%d ", ans[i]);
        puts("");
    }
    
    return 0;
}
