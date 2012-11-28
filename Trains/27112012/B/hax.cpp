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

int a[1111];

int main() {
    freopen("chaotic.in", "r", stdin);
    freopen("chaotic.out", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;
    for (int i = 0; i + 1 < n; i++) {
        if ( (i + 2 < n) && ( (a[i] < a[i + 1] && a[i + 1] < a[i + 2]) || (a[i] > a[i + 1] && a[i + 1] > a[i + 2]) )) {
            ans.push_back(i + 1);
            swap(a[i + 1], a[i + 2]);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] + 1 << " ";
    
    return 0;
}
