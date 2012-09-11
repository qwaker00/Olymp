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
#include <map>

typedef long long LL;
typedef unsigned long long ULL;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;

#define N 111111

pair<LL, char> a[N];
LL ans[255];
int n;

int main() {
    freopen("tower.in", "r", stdin);
    freopen("tower.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> a[i].first >> a[i].second;
    	ans[a[i].second] += a[i].first * a[i].first * 5;
    }
    sort(a, a + n, greater<pair<LL,char> >());
    for (int i = 1; i < n; ++i) {
    	ans[a[i - 1].second] -= a[i].first * a[i].first;
    }
    cout << "R - " << ans['R'] << endl;
    cout << "G - " << ans['G'] << endl;
    cout << "B - " << ans['B'] << endl;

    return 0;
}
