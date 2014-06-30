#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef long long LL;
typedef double LD;
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout.precision(10);
    LD s = 0;
    for (int i = 0; i < 200000; ++i) {
        LD x = s + LD(4) / (8 * i + 1) + LD(-2) / (8 * i + 4) + LD(-1) / (8 * i + 5) + LD(-1) / (8 * i + 6);
        cout << LL(x) << ",";
        s = (x - LL(x)) * 16;
    }
    return 0;
}
