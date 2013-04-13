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


string Names[4] = {"Moscow", "Minsk", "Helsinki", "Berlin"};
int d[4][4] = { {0, 49, 57, 120},
                {45, 0, 100, 52},
                {1000000, 1000000, 0, 133},
                {115, 1000000, 1000000, 0}
             };

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
        
    string s1, s2;
    cin >> s1 >> s2;
    int a1 = find(Names, Names + 4, s1) - Names;
    int a2 = find(Names, Names + 4, s2) - Names;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    cout << d[a1][a2] << endl;    
    return 0;
}
