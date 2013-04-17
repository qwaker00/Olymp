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

int dx[] = {2, 2, 1, -1}, dy[] = {1, -1, -2, -2};

map< pair<int, int>, int > mem;

bool Win(int x, int y, int n) {
    if (-x+y >= n || x+y >= n || x-y >= n || -x-y >= n) return 1;

    map< pair<int, int>, int >::iterator i = mem.find( make_pair(x, y) );
    if (i != mem.end()) return i->second;

    int& result = mem[make_pair(x, y)] = 0;
    for (int i = 0; i < 4; ++i) {
        if (!Win(x + dx[i], y + dy[i], n)) {            
            result = 1;
            break;
        }
    }
    return result;
}


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    int N;
    cin >> N;
    cout << 2 - Win(0, 0, N) << endl;
    
    return 0;
}
