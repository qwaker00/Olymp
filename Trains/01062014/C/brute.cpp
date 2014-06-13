#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    for (int len = 3; len < 14; ++len) {
        cout << "len = " << len << " good ones " << endl;
        vector<int> p;
        for (int i = 1; i <= len; ++i) p.push_back(i);

        do {
            vector<int> bkp = p;
            int f = 0, g = 0;
            // calc g
            for (int ii = 0; ii < p.size(); ++ii) {
                g += (ii + 1 > p[ii]) ? ii + 1 - p[ii] : 0;
            }
            // calc f
            for (int targ = 1; targ <= p.size(); ++targ) {
                int pl;
                for (pl = 0; pl < p.size(); ++pl) {
                     if (p[pl] == targ) {
                         break;
                     }
                }
                for (int lft = pl - 1; lft >= targ - 1; --lft) {
                    swap(p[lft], p[lft + 1]);
                    ++f;
                }
            }
            p = bkp;
            if (f != g) {
                /*
                cout << "f = " << f << " g = " << g << endl;
                for (int i = 0; i < p.size(); ++i) {
                    cout << p[i] << " ";
                }
                cout << endl;
                */
                bool occur = false;
                for (int fi = 0; fi < p.size(); ++fi) {
                    for (int si = fi + 1; si < p.size(); ++si) {
                        for (int ti = si + 1; ti < p.size(); ++ti) {
                            if (p[fi] > p[si] && p[si] > p[ti]) {
                                  occur = true;
                            }
                        }
                    }
                }
                if (occur) {
//                    cout << "have" << endl;
                } else {
                    cout << "bad" << endl;
                }
            }
        } while (next_permutation(p.begin(), p.end()));
    }
}
