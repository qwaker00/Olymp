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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

const int N = 111;

char w[N][N][N];

string s[N*N];

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    int n, m, k;
    cin >> k >> n >> m;
    cin.ignore();

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) gets(w[i][j]); 
    } 

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            for (int q = 0;  q < k; ++q) s[i * m + j] += w[q][i][j];
        }
    n = n * m;
    sort(s, s + n);
    cout << unique(s, s + n) - s << endl;
    

    return 0;
}
