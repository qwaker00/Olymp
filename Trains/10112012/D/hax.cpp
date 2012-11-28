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

map<string, int> ids;
map<long long, int> hash[11][11];
int n, m, l, c[111];
char s[1111111];

int GetId(char * s) {
    static int id = 0;
    int& t = ids[s];
    if (!t) {
        t = ++id;
    }
    return t;
}


int main() {
    freopen("database.in", "r", stdin);
    freopen("database.out", "w", stdout);

    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(s);
        l = strlen(s);
        int last = 0, it = 0;
        for (int j = 0; j < l; j++) if (s[j] == ',') {
            s[j] = 0;
            
            c[it++] = GetId(s + last);
            last = j + 1;
        }
        c[it] = GetId(s + last);

        for (int j = 0; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                int& t = hash[j][k][ 100001ll * c[j] + c[k] ];
                if (t) {
                    cout << "NO" << endl;
                    cout << t << " " << i + 1 << endl;
                    cout << j + 1 << " " << k + 1 << endl;
                    return 0;
                }
                t = i + 1;
            }
        }
    }
    cout << "YES" << endl;
    
    return 0;
}
