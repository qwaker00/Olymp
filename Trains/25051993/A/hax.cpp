#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cassert>

using namespace std;

char ans[5555][5555];
bool can[27];

const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m;

void put(int x, int y, int xx, int yy) {
    memset(can, 1, sizeof(can));
    for (int i = 0; i < 4; ++i) {
        int xxx = x + dx[i];
        int yyy = y + dy[i];
        if (xxx < 0 || yyy < 0 || xxx >= n || yyy >= m) continue;
        if (ans[xxx][yyy])
            can[ans[xxx][yyy] - 'a'] = 0;
    }
    for (int i = 0; i < 4; ++i) {
        int xxx = xx + dx[i];
        int yyy = yy + dy[i];
        if (xxx < 0 || yyy < 0 || xxx >= n || yyy >= m) continue;
        if (ans[xxx][yyy])
            can[ans[xxx][yyy] - 'a'] = 0;
    }
    while (!can[ans[x][y]]) ++ans[x][y];
    ans[x][y] += 'a';
    ans[xx][yy] = ans[x][y];
}

int main() {
    freopen("domino.in", "r", stdin);
    freopen("domino.out", "w", stdout);

    scanf("%d%d", &n, &m);

    if (n == 1 && m == 2) {
        cout << "aa" << endl;
        return 0;
    }
    if (m == 1 && n == 2) {
        cout << "a" << endl;
        cout << "a" << endl;
        return 0;
    }

    if (n % 2 == m % 2) {
        return 0;
    }
    int swaped = 0;
    if (n % 2 == 1) {
        swap(n, m);
        swaped = 1;
    }


    if (n >= 6 && m >= 5) {
        for (int i = 0; i + 1 < m; i += 2) {
            put(0, i, 0, i + 1);
        }
        put(0, m - 1, 1, m - 1);

        for (int i = 1; i < n - 3; i += 2) {
            put(i, 0, i + 1, 0);

            for (int j = 1; j < m - 2; j += 2) {
                put(i, j, i, j + 1);
                put(i + 1, j, i + 1, j + 1);
            }

            put(i, m - 2, i + 1, m - 2);
            put(i + 1, m - 1, i + 2, m - 1);
        }

        put(n - 1, 0, n - 1, 1);
        put(n - 1, 2, n - 2, 2);
        put(n - 2, 0, n - 3, 0);
        put(n - 2, 1, n - 3, 1);
        for (int i = 2; i < m - 1; i += 2) {
            put(n - 3, i, n - 3, i + 1);
            put(n - 2, i + 1, n - 2, i + 2);
            put(n - 1, i + 1, n - 1, i + 2);
        }
    } else {
        return 0;
    }


    if (!swaped) {
        for (int i= 0; i < n; ++i)  {
               for (int j = 0; j < m; ++j)
                   putchar(ans[i][j]);
               putchar('\n');
        }
    } else {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                putchar(ans[j][i]);
            putchar('\n');
        }
    }
    return 0;
}
