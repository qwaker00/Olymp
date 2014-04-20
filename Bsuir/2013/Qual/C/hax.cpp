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

int len[1111111];
int s[1111111];
int mi[7], ma[7];
LL c[14];
vector<int> bysum[7][77];
vector<int> bysum2[7][77];

void Calc(LL x) {
    x--;

    if (x < 10) {
        cout << x << endl;
        return;
    }
    for (int i = 1; i < 14; ++i) {
        if (x >= c[i]) {
            x -= c[i];
            continue;
        }
        if ((i & 1) == 0) {
            int ii = i >> 1;
            for (int j = mi[ii]; j <= ma[ii]; ++j) {
                if (x >= bysum2[ii][s[j]].size()) {
                    x -= bysum2[ii][s[j]].size();
                } else {
                    cout << j << bysum2[ii][s[j]][x] << endl;
                    return;
                }
            }
            throw 2;
        } else {
            int ii = i >> 1;
            for (int j = mi[ii]; j <= ma[ii]; ++j) {
                if (x >= bysum2[ii][s[j]].size() * 10) {
                    x -= bysum2[ii][s[j]].size() * 10;
                } else {
                    int bs = bysum2[ii][s[j]].size();
                    cout << j << x / bs << bysum2[ii][s[j]][x % bs] << endl;
                    return;
                }
            }
            throw 3;
        }
    }
    throw 4;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    
    len[0] = 0;
    s[0] = 0;
    for (int i = 1; i < 1000000; ++i) {
        len[i] = len[i / 10] + 1;
        s[i] = s[i / 10] + i % 10;
        bysum[len[i]][s[i]].push_back(i);
        for (int j = len[i]; j < 7; ++j)
            bysum2[j][s[i]].push_back(i);
    }

//    int tc = 0;
//    for (int i = 0; i < 7; ++i) for (int j = 0; j < 77; ++j) tc += bysum[i][j].capacity() + bysum2[i][j].capacity();
//    cerr << tc*4 / (1024*1024) << endl;

    mi[1] = 1;
    ma[1] = 9;
    for (int i = 2; i < 7; ++i) mi[i] = mi[i - 1] * 10, ma[i] = ma[i - 1] * 10 + 9;

    c[1] = 10;
    for (int i = 1; i <= 6; ++i) {       
        for (int j = 1; j <= i * 9; ++j) {
            c[i + i] += LL(bysum[i][j].size()) * bysum2[i][j].size();
            c[i + i + 1] += LL(bysum[i][j].size()) * bysum2[i][j].size() * 10;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        LL x;
        cin >> x;
        Calc(x);
    }
    
//    cerr << clock() << endl;

    return 0;
}
