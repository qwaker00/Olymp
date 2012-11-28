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


int n, sum;

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    cin >> n;
    sum = 14;
    int i = 1;
    while (sum <= n) {
        if (i == 1) {
            if (n == 21) {
                cout << i << endl;
                return 0;
            }
        } else
        if (n - sum <= 12 && n - sum >= 2) { 
            cout << i << endl;
            return 0;
        }
        ++i;
        sum += 14;
    }    
    cout << -1 << endl;
    return 0;
}
