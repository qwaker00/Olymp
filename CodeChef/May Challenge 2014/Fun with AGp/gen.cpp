#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
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

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

#define PI 3.1415926535897932384626433832795
#define sqr(x) ((x)*(x))

using namespace std;


int main() {
//    ios::sync_with_stdio(false);

    freopen("seed", "r", stdin);
    int seed;
    cin >> seed;
    srand(seed);

    const int n = 50000;
    const int Q = 50000;
    const int R = 3;
    const int P1 = 17;
    const int P2 = 19;
    const int V = 100000;
    int T = 2;

    cout << T << endl;
    while (T--) {
        int N = n;
        cout << N << " " << Q << " " << R << " " << P1 << " " << P2 << "\n";
        for (int i = 0; i < N; ++i) cout << (rand() % V) << " ";
        cout << "\n";
        for (int i = 0; i < Q; ++i) {
            int t = rand() % 3;
            if (t == 0) {
                int l = (rand() % N) + 1;
                int r = l + rand() % (N - l + 1);
                cout << "0 " << (rand() % V) << " " << (rand() % V) << " " << l << " " << r << "\n";
            } else
            if (t == 1) {
                cout << "1 " << (rand() % N + 1) << " " << (rand() % V) << "\n";
            } else {
                int l = (rand() % N) + 1;
                int r = l + rand() % (N - l + 1);
                cout << "2 " << l << " " << r << "\n";
            }
        }
    }

    freopen("seed", "w", stdout);
    cout << seed + 1 << endl;
    
    return 0;
}
