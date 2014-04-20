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

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
#define TOP 4
#define BOT 5

int c[6];
int x = 1, y = 1;
int n, m;

void Down() {
    int t = c[TOP];
    c[TOP] = c[UP];
    c[UP] = c[BOT];
    c[BOT] = c[DOWN];
    c[DOWN] = t;
    ++x;
}

void Right() {
    int t = c[TOP];
    c[TOP] = c[LEFT];
    c[LEFT] = c[BOT];
    c[BOT] = c[RIGHT];
    c[RIGHT] = t;
    ++y;
}

void Left() {
    int t = c[TOP];
    c[TOP] = c[RIGHT];
    c[RIGHT] = c[BOT];
    c[BOT] = c[LEFT];
    c[LEFT] = t;
    --y;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    cin >> n >> m;

    c[TOP] = 1;
    c[BOT] = 6;
    c[RIGHT] = 3;
    c[LEFT] = 4;
    c[UP] = 5;
    c[DOWN] = 2;

    LL ans = 0;
    bool right = 1;
    while (x <= n) {
        while (true) {
            ans += c[TOP];
//            cerr << c[TOP] << " ";

            if (y == m && right) {
                Down();
//              cerr << " | " << ans << endl;
                break;
            } else
            if (y == 1 && !right) {
                Down();
//                cerr << " | " << ans << endl;
                break;
            } else
            if (right) {
                if ((m - y) % 4 == 0) {
                    ans += LL(c[TOP] + c[RIGHT] + c[LEFT] + c[BOT]) * (m - y) / 4 - c[TOP];
                    y = m;
                } else
                    Right();
            } else {
                if ((y - 1) % 4 == 0) {
                    ans += LL(c[TOP] + c[RIGHT] + c[LEFT] + c[BOT]) * (y - 1) / 4 - c[TOP];
                    y = 1;
                } else
                    Left();
            }
        }
        right = !right;
    }
    cout << ans << endl;
        
    
    return 0;
}
                     