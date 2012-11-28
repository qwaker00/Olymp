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

const int N = 5555;

int n;
vector<int> a[N];
pair<int, int> b[N];
int s;

int main() {
    freopen("dice.in", "r", stdin);
    freopen("dice.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
        s += b[i].first;
    } 
    sort(b, b + n);

    double ans = 0;
    int cur = s;
    for (int i = 0; i < n; ++i) {
        while (b[i].first--) {
            a[b[i].second].push_back(s--);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) ans += double(a[i][j]) / double(a[i].size());
    }
    
    cout.precision(10);
    cout << fixed;
    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i].size(); ++j) printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
