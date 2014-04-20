#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <deque>
#include <map>
#include <functional>
#include <numeric>
#include <sstream>
#include <complex>

using namespace std;

int a[100100];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        auto p = equal_range(a, a + n, a[i] - k);
        ans += p.second - p.first;
    }        
    cout << ans << endl;    
    return 0;
}
