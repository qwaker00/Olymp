#include "treap_array.h"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

using namespace std;

int main() {    
    const int n = 123897;
    treap_array<int> t(n), tt;
    for (int i = 0; i < n; ++i) t[i] = i;
    vector<int> v(n), vv;
    for (int i = 0; i < n; ++i) v[i] = i;

    srand(0);
    for (int i = 0; i < n; ++i) {
        int l = randint(0, n - 1);
        int r = randint(l, n);

        if (rand() & 1) {
            t.cut(l, r, tt);
            t.merge(tt, t);

            vv.assign(v.begin() + l, v.begin() + r);
            v.erase(v.begin() + l, v.begin() + r);
            for (int j = vv.size() - 1; j >= 0; --j) v.insert(v.begin(), vv[j]);
        } else {
            t.cut(l, r, tt);
            t.merge(tt);

            vv.assign(v.begin() + l, v.begin() + r);
            v.erase(v.begin() + l, v.begin() + r);
            for (int j = 0; j < vv.size(); ++j) v.push_back(vv[j]);
        }

        if ((i & (i - 1)) == 0) cerr << "* " << i << endl;

        for (int j = 0; j < v.size(); ++j) if (v[j] != t[j]) {
            cerr << "Errorrrrr!!!" << endl;
            cerr << l << " " << r << endl;
            for (int k = 0; k < t.size(); ++k) cerr << t[k] << " ";
            cerr << endl;
            for (int k = 0; k < v.size(); ++k) cerr << v[k] << " ";
            cerr << endl;
            return 1;
        }
    }
    cerr << clock() << endl;

    return 0;
}
