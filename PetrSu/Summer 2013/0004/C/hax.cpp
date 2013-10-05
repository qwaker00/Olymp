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

int T;
char s[111111];
int id[256];
set< pair< char, pair<int, int> > > palka;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
        
    id['U'] = 1;
    id['R'] = 2;
    id['D'] = 3;
    id['L'] = 0;

    scanf("%d\n", &T);
    while (T--) {
        gets(s);
        palka.clear();

        int l = 0;
        int x = 0, y = 0;
        while (s[l]) {
            int i = id[s[l]];
            int xx = x + dx[i];
            int yy = y + dy[i];
            palka.insert( make_pair(i, make_pair(x, y)) );
            palka.insert( make_pair((i + 2) & 3, make_pair(xx, yy)) );
            x = xx;
            y = yy;
            ++l;
        }

        int dir = palka.begin()->first;
        int sx = palka.begin()->second.first;
        int sy = palka.begin()->second.second;
        x = sx + dx[dir];
        y = sy + dy[dir];
        int l1 = 1;
        while (x != sx || y != sy) {
            if (palka.count(make_pair( (dir + 1) & 3, make_pair(x, y)))) {
                dir = (dir + 1) & 3;
                x = x + dx[dir];
                y = y + dy[dir];                
                ++l1;
            } else
                dir = (dir + 3) & 3; 
        }

        puts(l1 == l ? "1" : "2");
    }    
    
    return 0;
}
