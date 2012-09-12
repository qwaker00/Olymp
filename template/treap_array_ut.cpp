#include "treap_array.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace qwaker;
using namespace std;

int main() {
    const int n = 100000;
    treap_array<int> t(n), tt;
    for (int i = 0; i < n; ++i) t[i] = i;

    LL sum = 0;
    for (int i = 0; i < n; ++i) sum += t[i];
    cerr << sum << endl;

    for (int i = 0; i < n; ++i) {
        int l = randint(0, n - 1);
        int r = randint(l, n);
        t.cut(l, r, tt);
        t.merge(tt, t);
    }
    sum = 0;
    for (int i = 0; i < n; ++i) sum += t[i];
    cerr << sum << endl;
    cerr << t.size() << endl;
    cerr << "time: " << clock() << endl;

    return 0;
}
