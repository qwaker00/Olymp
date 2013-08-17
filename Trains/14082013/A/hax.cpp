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
#include <assert.h>

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

char was[8][8] [8][8] [8][8] [8][8] [2];
int dx[8] = {1,  1, -1, -1, 0, -1, 1,  0};
int dy[8] = {1, -1, -1,  1, 1,  0, 0, -1};

bool noKing(int x, int y, int x1, int y1, int kx, int ky) {
    return max(abs(x - kx), abs(y - ky)) + max(abs(x1 - kx), abs(y1 - ky)) != max(abs(x - x1), abs(y - y1));
}

bool Attacked(int x, int y, int w1x, int w1y, int w2x, int w2y, int w3x, int w3y) {
    if ( max(abs(w1x - x), abs(w1y - y)) == 1 ) return true; // king
    if ( (x != w2x || y != w2y) && abs(w2x - x) == abs(w2y - y) ) {
        if (noKing(w2x, w2y, x, y, w1x, w1y)) {
            return true;
        }
    }
    if ( (x != w3x || y != w3y) && abs(w3x - x) == abs(w3y - y) ) {
        if (noKing(w3x, w3y, x, y, w1x, w1y)) {
            return true;
        }
    }
    return false;
}

int IT = 0;

bool wins(char w1x, char w1y, char w2x, char w2y, char w3x, char w3y, char b1x, char b1y, bool turn, int depth) {
    if (depth > 3) {
        return ((abs(w2x - w2y) + abs(w3x - w3y))&1) == 1;
    }

//    cerr << w1x << " " << w1y << " " << w2x << " " << w2y << " " << w3x << " " << w3y << " " << b1x << " " << b1y << "\n";
    char& ans = was[w1x][w1y][w2x][w2y][w3x][w3y][b1x][b1y][turn];
    if (ans >> 1) return ans & 1;
    if (ans & 1) return turn == 1;

//    if (++IT % 1000000 == 0) cerr << IT << endl;
    ans = 1;
    if (turn == 1) {
        int ways = 0;
        for (int i = 0; i < 8; ++i) {
            int x = b1x + dx[i];
            int y = b1y + dy[i];
            if (x < 0 || y < 0 || x > 7 || y > 7) continue;
            if (!Attacked(x, y, w1x, w1y, w2x, w2y, w3x, w3y)) {
                if (x == w2x && y == w2y) {
                    ans = 3;
                    break;
                }
                if (x == w3x && y == w3y) {
                    ans = 3;
                    break;
                }
                if (!wins(w1x, w1y, w2x, w2y, w3x, w3y, x, y, 0, depth + 1)) {
                    ans = 3;
                    break;
                }
                ++ways;
            }
        }
        if (ways == 0 && !Attacked(b1x, b1y, w1x, w1y, w2x, w2y, w3x, w3y)) {
            ans = 3;
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            int x = w1x + dx[i];
            int y = w1y + dy[i];
            if (x < 0 || y < 0 || x > 7 || y > 7) continue;
            if (x == w1x && y == w1y) continue;
            if (x == w2x && y == w2y) continue;
            if (max(abs(x - b1x), abs(y - b1y)) == 1) continue;
            if (!wins(x, y, w2x, w2y, w3x, w3y, b1x, b1y, 1, depth + 1)) {
                ans = 3;
                break;
            }
        }
        if (ans != 3) {
            for (int i = 0; i < 4 && ans != 3; ++i) {
                int j = 1;
                while (true) {
                    int x = w2x + dx[i] * j;
                    int y = w2y + dy[i] * j;
                    if (x < 0 || y < 0 || x > 7 || y > 7) break;
                    if (w1x == x && w1y == y) break;
                    if (w3x == x && w3y == y) break;
                    if (b1x == x && b1y == y) {
                        ans = 3;
                        break;
                    }
                    if (!wins(w1x, w1y, x, y, w3x, w3y, b1x, b1y, 1, depth + 1)) {
                        ans = 3;
                        break;
                    }
                    ++j;
                }
            }
        }
        if (ans != 3) {
            for (int i = 0; i < 4 && ans != 3; ++i) {
                int j = 1;
                while (true) {
                    int x = w3x + dx[i] * j;
                    int y = w3y + dy[i] * j;
                    if (x < 0 || y < 0 || x > 7 || y > 7) break;
                    if (w1x == x && w1y == y) break;
                    if (w2x == x && w2y == y) break;
                    if (b1x == x && b1y == y) {
                        ans = 3;
                        break;
                    }
                    if (!wins(w1x, w1y, w2x, w2y, x, y, b1x, b1y, 1, depth + 1)) {
                        ans = 3;
                        break;
                    }
                    ++j;
                }
            }
        }
    }
    if (ans != 3) ans = 2;

    return ans & 1;
}


int main() {
    freopen("bishops.in", "r", stdin);
    freopen("bishops.out", "w", stdout);
    
    string w1, w2, w3;
    string b1;
    string turn;

    cin >> w1 >> w2 >> w3;
    cin >> b1;
    cin >> turn;

    if (turn == "white") {
        if (wins(w1[0] - 'a', w1[1] - '1', w2[0] - 'a', w2[1] - '1', w3[0] - 'a', w3[1] - '1', b1[0] - 'a', b1[1] - '1', 0, 0)) {
            cout << "white wins" << endl;
        } else {
            cout << "draw" << endl;
        }
    } else {
        if (wins(w1[0] - 'a', w1[1] - '1', w2[0] - 'a', w2[1] - '1', w3[0] - 'a', w3[1] - '1', b1[0] - 'a', b1[1] - '1', 1, 1)) {
            cout << "draw" << endl;
        } else {
            cout << "white wins" << endl;
        }
    }
    cerr << clock() << endl;
        
    
    return 0;
}