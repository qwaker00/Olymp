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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

int n;
char s[111][111];

void Right(int x, int y, int& nx, int& ny) {
    nx = x;
    ny = y + 1;
}
void UpRight(int x, int y, int& nx, int& ny) {
    if (y & 1) {
        nx = x - 1;
        ny = y - 1;
    } else {
        nx = x;
        ny = y + 1;
    }
}
void UpLeft(int x, int y, int& nx, int& ny) {
    if (y & 1) {
        nx = x - 1;
        ny = y - 1;
    } else {
        nx = x;
        ny = y - 1;
    }
}
void RightR(int x, int y, int& nx, int& ny) {
    nx = x;
    ny = y - 1;
}
void UpRightR(int x, int y, int& nx, int& ny) {
    if (y & 1) {
        nx = x;
        ny = y - 1;
    } else {
        nx = x + 1;
        ny = y + 1;
    }
}
void UpLeftR(int x, int y, int& nx, int& ny) {
    if (y & 1) {
        nx = x;
        ny = y + 1;
    } else {
        nx = x + 1;
        ny = y + 1;
    }
}


int main() {
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    
    int it = 0;
    while (true) {
        ++it;
        scanf("%d\n", &n);
        if (n == 0) break;

        for (int i = 0; i < n; ++i) {
            gets(s[i]);
        }


        bool ok[6][2] = {{true, true}, {true, true}, {true, true},{true, true}, {true, true}, {true, true}};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i + i + 1; ++j) {
                int nx, ny;

                Right(i, j, nx, ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < nx + nx + 1 && s[nx][ny] != s[i][j]) {
                    ok[0][s[i][j] - 48] = false;
                }
                UpRight(i, j, nx, ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < nx + nx + 1 && s[nx][ny] != s[i][j]) {
                    ok[1][s[i][j] - 48] = false;
                }
                UpLeft(i, j, nx, ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < nx + nx + 1 && s[nx][ny] != s[i][j]) {
                    ok[2][s[i][j] - 48] = false;
                }

                RightR(i, j, nx, ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < nx + nx + 1 && s[nx][ny] != s[i][j]) {
                    ok[3][s[i][j] - 48] = false;
                }
                UpRightR(i, j, nx, ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < nx + nx + 1 && s[nx][ny] != s[i][j]) {
                    ok[4][s[i][j] - 48] = false;
                }
                UpLeftR(i, j, nx, ny);
                if (nx >= 0 && nx < n && ny >= 0 && ny < nx + nx + 1 && s[nx][ny] != s[i][j]) {
                    ok[5][s[i][j] - 48] = false;
                }
            }
        }
            
        if (it > 1) puts("");
        printf("Puzzle %d\n", it);

        bool good = false;
        for (int i = 0; i < 6; ++i) {
            if (ok[(i >= 3) ? (i - 3) : (i + 3)][1] && ok[i][0]) {
                good = true;
            }
        }
        if (good) {
            puts("Parts can be separated");
        } else
            puts("Parts cannot be separated");
    }

    return 0;
}
