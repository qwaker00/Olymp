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

string format3(string s) {
    while (s.length() < 3)
        s += ' ';
    return s;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {          
        map<pair<string, string>, string > data;
        set<string> R;
        set<string> C;
        string a, b, c;

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c;
            data[make_pair(a, b)] = c;
            R.insert(a);
            C.insert(b);
        }
        int cc = C.size();
        int rc = R.size();

        putchar('+');
        for (int i = 0; i < cc + 1; ++i) printf("---+");
        puts("");
        
        printf("|   |");
        for (set<string>::const_iterator i = C.begin(); i != C.end(); ++i) 
            cout << format3(*i).c_str() << '|';
        puts("");

        putchar('+');
        for (int i = 0; i < cc + 1; ++i) printf("---+");
        puts("");

        for (set<string>::const_iterator i = R.begin(); i != R.end(); ++i) {
            cout << '|' << format3(*i) << '|';

            for (set<string>::const_iterator j = C.begin(); j != C.end(); ++j) 
                cout << format3(data[make_pair(*i, *j)]).c_str() << '|';
            puts("");

            putchar('+');
            for (int i = 0; i < cc + 1; ++i) printf("---+");
            puts("");
        }
    }    

    return 0;
}
