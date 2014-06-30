#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int f[555][555];
int was[555][555];
int d[555][555];
int p[555][555];
int IT = 0;

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int nei(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        const int xx = x + dx[i];
        const int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= n || yy >= m || f[xx][yy] != '.') continue;
        return i + 1;
    }
    return 0;
}

void revout(int x, int y, int c) {
    if (c == 0) return;
    int rd = p[x][y];
    revout(x - dx[rd] * 2, y - dy[rd] * 2, c - 1);
    printf("%d %d %d %d\n", x - dx[rd] * 2 + 1, y - dy[rd] * 2 + 1, x - dx[rd] + 1, y - dy[rd] + 1);
}

int main() {
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);

    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) f[i][j] = getchar();
        scanf("\n");
    }

    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        f[x][y] = -i - 1;
         scanf("%d%d", &x, &y);
        --x;
        --y;
        f[x][y] = -i - 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == '.') {
                if (nei(i, j)) {
                    puts("Yes");
                    puts("0");
                    return 0;
                }
            }
        }
    }


    IT = 1;
    queue< pair<int, int> > q;
    for (int _x =0 ; _x < n; ++_x) {
        for (int _y= 0; _y < m; ++_y) {
            if (f[_x][_y] == '.') {
                q.push(make_pair(_x, _y));
                d[_x][_y] = 0;
                was[_x][_y] = IT;
            }
        }
    }

    while (!q.empty()) {
       pair<int, int> t = q.front(); q.pop();
       for (int i = 0; i < 4; ++i) {
            int xx = t.first + dx[i];
            int yy = t.second + dy[i];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (f[xx][yy] < 0) {
                int xxx = xx + dx[i];
                int yyy = yy + dy[i];
                if (xxx < 0 || yyy < 0 || xxx >= n || yyy >= m) continue;
                if (f[xxx][yyy] == f[xx][yy] && (was[xxx][yyy] != IT || d[xxx][yyy] > d[t.first][t.second] + 1)) {
                    q.push(make_pair(xxx, yyy));
                    was[xxx][yyy] = IT;
                    d[xxx][yyy] = d[t.first][t.second] + 1;
                    p[xxx][yyy] = i;
                }
            }
        }
    }

    int ansd = 1e9, ansi, ansj, ansii, ansjj;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (was[i][j]) {
                for (int di = 0; di < 4; ++di) {
                    int ii = i + dx[di];
                    int jj = j + dy[di];
                    if (ii < 0 || jj < 0 || ii >= n || jj >= m || was[ii][jj] != IT) continue;
                    if (d[i][j] + d[ii][jj] < ansd) {
                        ansd = d[i][j] + d[ii][jj];
                        ansi = i;
                        ansj = j;
                        ansii = ii;
                        ansjj = jj;
                    }
                }
            }

    if (ansd < 1e9) {
            puts("Yes");
            printf("%d\n", d[ansi][ansj] + d[ansii][ansjj]);
            revout(ansi, ansj, d[ansi][ansj]);
            revout(ansii, ansjj, d[ansii][ansjj]);
    } else
            puts("No");

    return 0;
}
