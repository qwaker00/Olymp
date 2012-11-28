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

const int N = 11111;

string w[N];

void print(int x, int len) {
    for (int j = len - 1; j >= 0; --j)
                if (x & (1 << j)) cout << '1';
                else cout << '0';
}

int main() {
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    
    int n;
    cin >> n;

    int len = 1;
    while ((1 << len) < n) ++len;

    int left = (1 << len) - n; 
    int i = 0;

        for (int done = 0; done < n; ++i) {
            int lb = 0;
            if (done < left) lb = 1;
            //cerr << i << endl;

            for (int j = len - 1; j >= lb; --j)
                if (i & (1 << j)) cout << '1';
                else cout << '0';
            cout << endl; 
            
            if (done < left) ++i;
            ++done;
        }

        
    
    return 0;
}
